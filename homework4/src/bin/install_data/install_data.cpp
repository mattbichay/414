#include <iostream>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include "shared_mem.h"
#include "shm.h"

using namespace std;

int main(int argc, char * argv[])
{
    if (argc < 2)
        return ERROR;

    std::string in_file(argv[1]);
    
    ifstream file(in_file, ifstream::in);

    Shm_Struct * data = (Shm_Struct *)connect_shm(KEY, sizeof(Shm_Struct) * TOTAL);
    if (data == NULL)
        return ERROR;

    std::string line;
    while(std::getline(file, line))
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
            data[index].is_valid = 0;
            continue;
        }
        
        sleep(time);
        data[index].is_valid = 1;
        data[index].x = x;
        data[index].y = y;

    }
    file.close();

    return OK;
}
