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

/* Initialize_manager is an internal function used for initializing the
 * Shm_Metadata to default values. */
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

/* connect_shm takes a key and size input and returns a shared memory address
 * pointer. If an error occurs, NULL is returned.
 */
void * connect_shm(int key, int size)
{
    /* Check if the # of connections is already larger than the limit */
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

    /* Initialize the shm metadate in the manager struct with key metadata */
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

/* detach_shm takes a shared memory address and detaches it for use, freeing it
 * up for other connections
 */
int detach_shm(void * addr)
{
    if (connections < 0)
        return ERROR;

    /* Find the shm address in the shm_manager and shmdt that address if it
     * exists */
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

/* destroy_shm takes an input key and detaches and removes all shared memory
 * segments associated with the input key
 */
int destroy_shm(int key)
{
    if (connections < 0)
        return ERROR;
    
    /* find the shmid in the Shm_manager and detach it. */
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

    /* If the shmid exists, use shmctl to remove the id */
    if (shmid < 0)
        return ERROR;
    
    if (shmctl(shmid, IPC_RMID, NULL) < 0)
        return ERROR;
    return OK;
}
