/* Name: Matthew Bichay
 * Course: Systems Development in the Unix Environment
 * Semester: Fall 2017
 * Description: Header file for the Shm_Struct definition and some import
 * #defines for the install_data and monitor_data binaries
 */
#ifndef SHM_H
#define SHM_H

/* Key for shared memory segment */
#define KEY 1234
/* Total # of shared memory segment to look at */
#define TOTAL 20

/* Definition of the Shm_Struct datatype */
struct Shm_Struct
{
    int is_valid;
    float x;
    float y;

    Shm_Struct() : is_valid(0), x(0), y(0) {}

};

#endif
