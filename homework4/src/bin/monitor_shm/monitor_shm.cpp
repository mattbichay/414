#include "shared_mem.h"
#include "shm.h"
#include <unistd.h>
#include <iostream>

#define DEFAULT_TIME 30;

using namespace std;

int main(int argc, char *argv[])
{
    int time = DEFAULT_TIME;
    if (argc > 1)
        time = atoi(argv[1]);

    Shm_Struct * data = (Shm_Struct *)connect_shm(KEY, sizeof(Shm_Struct) * TOTAL);
    if (data == NULL)
        return ERROR;

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
}
