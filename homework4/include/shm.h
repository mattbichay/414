#ifndef SHM_H
#define SHM_H

#define KEY 1234
#define TOTAL 20

struct Shm_Struct
{
    int is_valid;
    float x;
    float y;

    Shm_Struct() : is_valid(0), x(0), y(0) {}

};

#endif
