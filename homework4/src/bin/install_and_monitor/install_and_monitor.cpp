#include <pthread.h>
#include "log_mgr.h"

#define DEFAULT_TIME 30;

using namespace std;


static ifstream F_STREAM;
static Shm_Struct DATA[TOTAL];

int main(int argc, char * argv[])
{
    if (argc < 2)
    {
        log_event(FATAL, "Error:%s", "Input file is required.");
        return ERROR;
    }
    int time = DEFAULT_TIME;
    if (argc > 2)
        time = atoi(argv[1]);

    std::string in_file(argv[1]);
    F_STREAM = ifstream(in_file, ifstream::in);
}
