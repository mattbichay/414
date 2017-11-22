/* Name: Matthew Bichay
 * Course: Systems Development in the Unix Environment
 * Semester: Fall 2017
 * Description: Header file for the shared_mem library. Provides function
 * prototypes for the connect_shm, destroy_shm, and detach_shm methods.
 */

#ifndef SHARED_MEM_H
#define SHARED_MEM_H


#define OK 0
#define ERROR -1
#define LIMIT 4096
#define ANY_SHM_ADDR 0x000000

/* A struct to track the metadata of the shared memory segments */
typedef struct
{
    int shmid;
    int key;
    void* addr;
    int in_use;
} Shm_Metadata;

/* connect_shm takes a key and size input and returns a shared memory address
 * pointer. If an error occurs, NULL is returned.
 */
void * connect_shm(int key, int size);

/* detach_shm takes a shared memory address and detaches it for use, freeing it
 * up for other connections
 */
int detach_shm(void * addr);

/* destroy_shm takes an input key and detaches and removes all shared memory
 * segments associated with the input key
 */
int destroy_shm(int key);

#endif
