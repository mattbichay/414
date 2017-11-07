/* Name: Matthew Bichay
 * Course: Systems Development in the Unix Environment
 * Semester: Fall 2017
 * Description: Main file for the my_fortune binary.
 */
#include <iostream>
#include <unistd.h>
#include <limits.h>
#include <cstdlib>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "log_mgr.h"

#define QUITCHAR 'q'
#ifndef HOST_NAME_MAX
#define HOST_NAME_MAX _POSIX_HOST_NAME_MAX
#endif
using namespace std;

/* Paths to the fortune application */
const std::string ABSAROKA_FORTUNE = "/home/unix_dev/NOTES/fortune_absaroka/fortune";
const std::string DEV3_FORTUNE = "/home/unix_dev/NOTES/fortune/fortune";

int origflags;
int newflags;

/* This method takes a string and returns a copy of that string with all
 * characters propperly capitalized
 */
string upper(string in_str)
{
    for (int i = 0; i < in_str.size(); ++i)
        in_str[i] = toupper(in_str[i]);
    return in_str;
}

/* This method takes an integer argument, reverts the current executable's
 * flags, and then exits with that integer argument. This method is used as
 * a signal handler for signal interrupts
 */
void revert_flags(int sig)
{
    if (fcntl(0, F_SETFL, origflags < 0))
    {
        log_event(FATAL, "Error:%s", "original flags unable to be restored");
        perror("fcntl");
        exit(1);
    }
    exit(sig);
}

int main()
{
    char c = '\0';

    /* Make standard input nonblocking */
    int readrtn, return_val;
    if ((origflags = fcntl(0, F_GETFL, 0)) < 0)
    {   log_event(FATAL, "Error:%s", "original flags were unable to be attained");
        perror("fcntl F_GETFL error");
        exit(1);
    }
    newflags = origflags|O_NONBLOCK;
    if ((return_val = fcntl(0, F_SETFL, newflags)) < 0)
    {
        log_event(FATAL, "Error:%s", "new flags were unable to be set");
        perror("fcntl");
        exit(1);
    }


    /* Setup for fortune path */
    char hostname[HOST_NAME_MAX];
    gethostname(hostname, HOST_NAME_MAX);
    string fortune_executable = ABSAROKA_FORTUNE;
    if (string(hostname) == "dev3")
        fortune_executable = DEV3_FORTUNE;
    log_event(INFO, "hostname:%s", hostname);
    log_event(INFO, "application:%s", fortune_executable.c_str());

    /* Initialize sufficiently large buffer for pipe */
    char readbuf[2000];
    FILE * pipe_in;

    /* Setup signal handlers */
    signal(SIGINT, revert_flags);

    while(c != QUITCHAR)
    {
        /* read stdin and write the first character to c */
        if ((readrtn = read(0, &c, 1)) < 0)
        {
            /* Open pipe */
            if (!(pipe_in = popen(fortune_executable.c_str(), "r")))
            {
                log_event(FATAL, "Error:%s", "failed to run executable");
                break;
            }
            /* Read buffer from opened pipe */
            while (fgets(readbuf, 2000, pipe_in) != NULL)
                /* Write to stdout using upper method */
                cout << upper(string(readbuf)) << endl;
            pclose(pipe_in);
            log_event(INFO, "%s", "fortune propperly printed");
            
            /* Random sleep */
            sleep((rand() % 15));
        }
    }
    /* Change back to original flags */
    revert_flags(0);
    return 0;
}
