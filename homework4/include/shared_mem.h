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

typedef struct
{
    int is_valid;
    float x;
    float y;
} Shm_Struct;

typedef struct
{
    int shmid;
    int key;
    void* addr;
    int pid;
    int in_use;
} Shm_Metadata;


void * connect_shm(int key, int size);
int detach_shm(void * addr);
int destroy_shm(int key);

#endif
