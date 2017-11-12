#include <iostream>
#include <fstream>
#include "shared_mem.h"


using namespace std;

int main(int argc, char * argv[])
{
    if (argc < 2)
        return ERROR;

    std::string in_file(argv[1]);
    
    ifstream file(in_file, ifstream::in);

    if (file.is_open())
        cout << "Hello World!" << endl;



    return OK;
}
