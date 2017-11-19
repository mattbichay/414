#include <iostream>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <signal.h>
#include "shared_mem.h"
#include "shm.h"
#include "log_mgr.h"

using namespace std;

static ifstream F_STREAM;
static Shm_Struct * DATA;

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
    exit(sig);
}

int main(int argc, char * argv[])
{
    if (argc < 2)
    {
        log_event(FATAL, "Error:%s", "Input file is required.");
        return ERROR;
    }

    std::string in_file(argv[1]);
    
    F_STREAM = ifstream(in_file, ifstream::in);
    
    DATA = (Shm_Struct *)connect_shm(KEY, sizeof(Shm_Struct) * TOTAL);
    if (DATA == NULL)
    {
        log_event(FATAL, "Error:%s", "Could not connect to shared memory.");
        return ERROR;
    }

    signal(SIGHUP, handle_sighup);
    signal(SIGTERM, handle_sigterm);

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

    if (destroy_shm(KEY) < 0)
    {
        log_event(FATAL, "Error:%s", "Could not destroy shared memory.");
        return ERROR;
    }
    return OK;
}
