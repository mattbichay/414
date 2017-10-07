#include <iostream>
#include <unistd.h>
#include <limits.h>
#include <cstdlib>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#define QUITCHAR 'q'

using namespace std;

const std::string ABSAROKA_FORTUNE = "/home/unix_dev/NOTES/fortune_absaroka/fortune";
const std::string DEV3_FORTUNE = "/home/unix_dev/NOTES/fortune/fortune";

string upper(string in_str)
{
    for (int i = 0; i < in_str.size(); ++i)
        in_str[i] = toupper(in_str[i]);
    return in_str;
}

int main()
{
    char c = '\0';
    int readrtn, return_val, origflags, newflags;
    if ((origflags = fcntl(0, F_GETFL, 0)) < 0)
        perror("fcntl F_GETFL error");
    newflags = origflags|O_NONBLOCK;
    if ((return_val = fcntl(0, F_SETFL, newflags)) < 0)
    {
        perror("fcntl");
        exit(1);
    }


    /* Setup for fortune path */
    char hostname[HOST_NAME_MAX];
    gethostname(hostname, HOST_NAME_MAX);
    string fortune_executable = ABSAROKA_FORTUNE;
    if (string(hostname) == "dev3")
        fortune_executable = DEV3_FORTUNE;
    char readbuf[2000];
    FILE * pipe_in;

    while(c != QUITCHAR)
    {
        if ((readrtn = read(0, &c, 1)) < 0)
        {
            if (!(pipe_in = popen(fortune_executable.c_str(), "r")))
            {
                break;
            } 
            while (fgets(readbuf, 2000, pipe_in) != NULL)
                cout << upper(string(readbuf)) << endl;
            pclose(pipe_in);
            sleep((rand() % 15));
        }
    }
    if (fcntl(0, F_SETFL, origflags < 0))
            perror("fcntl");
    return 0;
}
