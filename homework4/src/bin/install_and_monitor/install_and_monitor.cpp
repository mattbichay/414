/* Name: Matthew Bichay
 * Course: Systems Development in the Unix Environment
 * Semester: Fall 2017
 * Description: Main file for the install_and_monitor binary.
 */
#include <pthread.h>
#include <iostream>
#include <fstream>
#include <signal.h>
#include <unistd.h>
#include <sstream>
#include <cstdlib>
#include "log_mgr.h"
#include "shm.h"

/* default time for the monitor to run */
#define DEFAULT_TIME 30;

using namespace std;

/* Global static instantiations of the file stream, shared memory struct, and
 * time to loop */
static ifstream * F_STREAM;
static Shm_Struct DATA[TOTAL];
static int TIME;

/* handle_sighup provides implementation details for how install_and_monitor reacts to
 * receiving a SIGHUP signal
 * 
 * handle_sighup re-initializes all data to 0s and returns the file pointer to
 * the top of the file.
 */
void handle_sighup(int sig)
{
    F_STREAM->clear();
    F_STREAM->seekg(0, ios::beg);
    for (int i = 0; i < TOTAL; ++i)
    {
        DATA[i].is_valid = 0;
        DATA[i].x = 0;
        DATA[i].y = 0;
    }
}

/* handle_sigterm provides implementation details for how install_and_monitor reacts
 * to receiving a SIGTERM signal
 *
 * handle_sigterm closes the file stream and exits the program.
 */
void handle_sigterm(int sig)
{
    F_STREAM->close();
    exit(sig);
}

/* install_data provides implementation details for how install_and_monitor
 * installs data.
 */
void * install_data(void *ptr)
{
    /* While there are lines to read in the file */
    std::string line;
    while(std::getline(*F_STREAM, line))
    {
        int index, time;
        float x,y;

        std::stringstream lineStream(line);
        lineStream >> index;
        lineStream >> x;
        lineStream >> y;
        lineStream >> time;
        
        if (time < 0)
        {
            sleep(abs(time));
            DATA[index].is_valid = 0;
            continue;
        }
        
        sleep(time);
        DATA[index].is_valid = 1;
        DATA[index].x = x;
        DATA[index].y = y;

    }
    F_STREAM->close();
    pthread_exit(NULL);
}


/* monitor_data provides implementation details for how install_and_monitor
 * monitors data.
 */
void * monitor_data(void *ptr)
{
    for (int i = 0; i < TIME; ++i)
    {
        sleep(1);
        int valid = 0;
        float x = 0;
        float y = 0;
        for (int k = 0; k < TOTAL; ++k)
        {
            if (DATA[k].is_valid)
            {
                x += DATA[k].x;
                y += DATA[k].y;
                valid++;
            }
        }

        if (!valid)
        {
            cout << "At time " << i << ":no elements are active" << endl;
        }
        else
        {
            cout << "At time " << i << ":" << valid << " elements are active:x = " << x/float(valid) << " and y = " << y/(float(valid)) << endl;
        }
    }
    pthread_exit(NULL);
}


int main(int argc, char * argv[])
{
    /* Needs at least an input file */
    if (argc < 2)
    {
        log_event(FATAL, "Error:%s", "Input file is required.");
        return ERROR;
    }

    /* If another argument is present, set the time to monitor */
    TIME = DEFAULT_TIME;
    if (argc > 2)
        TIME = atoi(argv[1]);

    /* Open up a file stream */
    std::string in_file(argv[1]);
    F_STREAM = new ifstream(in_file.c_str(), ifstream::in);
   
    /* Register signals */
    signal(SIGHUP, handle_sighup);
    signal(SIGTERM, handle_sigterm);

    /* Initialize data */
    for (int i = 0; i < TOTAL; ++i)
    {
        DATA[i].is_valid = 0;
        DATA[i].x = 0;
        DATA[i].y = 0;
    }

    /* Open up two new threads */
    pthread_t thread1, thread2;
    int rtn_val;
    if ((rtn_val = pthread_create(&thread1, NULL, install_data, (void*) "thread1")) != 0)
    {
        log_event(FATAL, "Error:%s", "Thread could not be created.");
        return ERROR;
    }
    if ((rtn_val = pthread_create(&thread2, NULL, monitor_data, (void*) "thread2")) != 0)
    {
        log_event(FATAL, "Error:%s", "Thread could not be created.");
        return ERROR;
    }
    
    /* Wait for thread#2 to finish */
    pthread_join(thread2, NULL);
    return OK;
}
