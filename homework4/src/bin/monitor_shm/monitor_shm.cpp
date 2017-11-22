/* Name: Matthew Bichay
 * Course: Systems Development in the Unix Environment
 * Semester: Fall 2017
 * Description: Main file for the monitor_shm binary.
 */
#include "shared_mem.h"
#include "shm.h"
#include "log_mgr.h"
#include <unistd.h>
#include <iostream>
#include <cstdlib>

/* default time for the monitor to run */
#define DEFAULT_TIME 30;

using namespace std;

int main(int argc, char *argv[])
{
    /* If another argument is present, set the time to monitor */
    int time = DEFAULT_TIME;
    if (argc > 1)
        time = atoi(argv[1]);

    /* Connect to shared memory segment using KEY */
    Shm_Struct * data = (Shm_Struct *)connect_shm(KEY, sizeof(Shm_Struct) * TOTAL);
    if (data == NULL)
    {
        log_event(FATAL, "Error:%s", "Could not connect to shared memory segment.");
        return ERROR;
    }

    /* Loop for designated amount of time and monitor the data for valid
     * entries */
    for (int i = 0; i < time; ++i)
    {
        sleep(1);
        int valid = 0;
        float x = 0;
        float y = 0;
        for (int k = 0; k < TOTAL; ++k)
        {
            if (data[k].is_valid)
            {
                x += data[k].x;
                y += data[k].y;
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
    return OK;
}
