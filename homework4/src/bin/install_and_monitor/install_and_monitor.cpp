#include <pthread.h>
#include <iostream>
#include <fstream>
#include <signal.h>
#include <unistd.h>
#include <sstream>
#include "log_mgr.h"
#include "shm.h"

#define DEFAULT_TIME 30;

using namespace std;


static ifstream F_STREAM;
static Shm_Struct DATA[TOTAL];
static int TIME;

void handle_sighup(int sig)
{
    F_STREAM.clear();
    F_STREAM.seekg(0, ios::beg);
    for (int i = 0; i < TOTAL; ++i)
    {
        DATA[i].is_valid = 0;
        DATA[i].x = 0;
        DATA[i].y = 0;
    }
}

void handle_sigterm(int sig)
{
    F_STREAM.close();
    exit(sig);
}

void * install_data(void *ptr)
{
    std::string line;
    while(std::getline(F_STREAM, line))
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
    F_STREAM.close();
    pthread_exit(NULL);
}

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
    if (argc < 2)
    {
        log_event(FATAL, "Error:%s", "Input file is required.");
        return ERROR;
    }
    TIME = DEFAULT_TIME;
    if (argc > 2)
        TIME = atoi(argv[1]);

    std::string in_file(argv[1]);
    F_STREAM = ifstream(in_file, ifstream::in);
    
    signal(SIGHUP, handle_sighup);
    signal(SIGTERM, handle_sigterm);

    for (int i = 0; i < TOTAL; ++i)
    {
        DATA[i].is_valid = 0;
        DATA[i].x = 0;
        DATA[i].y = 0;
    }

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
    pthread_join(thread2, NULL);
    return OK;
}
