/* Name: Matthew Bichay
 * Course: Systems Development in the Unix Environment
 * Semester: Fall 2017
 * Description: Source file for the shared_mem library. Provides implementation
 * details for the connect_shm, destroy_shm, and detach_shm methods.
 */

#include "shared_mem.h"
#include <sys/shm.h>
#include <cstddef>

Shm_Metadata Shm_Manager[LIMIT];
int connections = -1;

void initialize_manager()
{
    for (int i = 0; i < LIMIT; ++i)
    {
        Shm_Manager[i].shmid = -999;
        Shm_Manager[i].key = -999;
        Shm_Manager[i].addr = NULL;
        Shm_Manager[i].in_use = 0;
    }
    connections++;
}

void * connect_shm(int key, int size)
{
    if (connections > LIMIT)
        return NULL;
    if (connections < 0)
        initialize_manager();

    int shmid;
    void* shmaddr = 0;

    shmid = shmget(key, size, IPC_CREAT | 0666);
    if (shmid < 0)
    {
        return NULL;
    }
    
    shmaddr = shmat(shmid, ANY_SHM_ADDR, 0);

    if (shmaddr < 0)
    {
        return NULL;
    }

    for (int i = 0; i < LIMIT; ++i)
    {
        if (!Shm_Manager[i].in_use)
        {
            Shm_Manager[i].shmid = shmid;
            Shm_Manager[i].key = key;
            Shm_Manager[i].addr = shmaddr;
            Shm_Manager[i].in_use = 1;
            connections++;
            return shmaddr;
        }
    }
    return NULL;
}


int detach_shm(void * addr)
{
    if (connections < 0)
        return ERROR;

    for (int i = 0; i < LIMIT; ++i)
    {
        if (Shm_Manager[i].addr == addr)
        {
            if (shmdt(addr) < 0)
                return ERROR;
            Shm_Manager[i].in_use = 0;
            connections--;
            return OK;
        }
    }
    return ERROR;
}


int destroy_shm(int key)
{
    if (connections < 0)
        return ERROR;

    int shmid = -1;
    for (int i = 0; i < LIMIT; ++i)
    {
        if (Shm_Manager[i].key == key)
        {
            if (detach_shm(Shm_Manager[i].addr) < 0)
                return ERROR;
            shmid = Shm_Manager[i].shmid;
        }
    }
    if (shmid < 0)
        return ERROR;
    
    if (shmctl(shmid, IPC_RMID, NULL) < 0)
        return ERROR;
    return OK;
}
