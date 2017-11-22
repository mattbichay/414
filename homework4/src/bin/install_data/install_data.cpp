/* Name: Matthew Bichay
 * Course: Systems Development in the Unix Environment
 * Semester: Fall 2017
 * Description: Main file for the install_data binary.
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <signal.h>
#include <cstdlib>
#include "shared_mem.h"
#include "shm.h"
#include "log_mgr.h"

using namespace std;

/* Static instantiations for the Shm_Struct and file streams */
static ifstream * F_STREAM;
static Shm_Struct * DATA;

/* handle_sighup provides implementation details for how install_data reacts to
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

/* handle_sigterm provides implementation details for how install_data reacts
 * to receiving a SIGTERM signal
 *
 * handle_sigterm detaches and destroys the shared memory segment. It then
 * closes the file stream and exits the program.
 */
void handle_sigterm(int sig)
{
    if (detach_shm(DATA) < 0)
    {
        log_event(FATAL, "Error:%s", "Could not detach from shared memory.");
        exit(ERROR);
    }
    if (destroy_shm(KEY) < 0)
    {
        log_event(FATAL, "Error:%s", "Could not destroy shared memory.");
        exit(ERROR);
    }
    F_STREAM->close();
    exit(sig);
}


int main(int argc, char * argv[])
{
    /* Check to see if input file is received */
    if (argc < 2)
    {
        log_event(FATAL, "Error:%s", "Input file is required.");
        return ERROR;
    }

    std::string in_file(argv[1]);
    
    /* Open a new file stream */
    F_STREAM = new ifstream(in_file.c_str(), ifstream::in);
    
    /* Open a new shared memory connection */
    DATA = (Shm_Struct *)connect_shm(KEY, sizeof(Shm_Struct) * TOTAL);
    if (DATA == NULL)
    {
        log_event(FATAL, "Error:%s", "Could not connect to shared memory.");
        return ERROR;
    }

    /* Register signals */
    signal(SIGHUP, handle_sighup);
    signal(SIGTERM, handle_sigterm);

    /* While there is still lines to read in the file, read line-by-line */
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

    /* cleanup */
    if (destroy_shm(KEY) < 0)
    {
        log_event(FATAL, "Error:%s", "Could not destroy shared memory.");
        return ERROR;
    }
    return OK;
}
