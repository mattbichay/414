#include <unistd.h>
#include <fcntl.h>
#include <ctime>
#include "log_mgr.h"

#include <iostream>


using namespace std;

int fd = ERROR;

int log_event(Levels l, const char *fmt, ...)
{
    if (fd < 0)
    {   std::string file = "logfile";
        if (set_logfile(file.c_str()) < 0)
            return ERROR;
    }
   	time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];
    time (&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer,sizeof(buffer),"%m %d %I:%M:%S %Y",timeinfo);
    std::string time_str(buffer);
	va_list args;
	va_start(args, fmt);
	char formatted_string[1000];
	vsprintf(formatted_string, fmt, args);
	std::string fmt_string = time_str + ":" + std::string(LEVEL_STRINGS[l]) + ":" + std::string(formatted_string);
	const char * string = fmt_string.c_str();

    /*
    if (write(fd, string, sizeof(string)))
    {
        return OK;
    }
    */

    cout << (write(fd, &string, fmt_string.length())) << endl;
    cerr << strerror(errno) << endl;
    return ERROR;
}

int set_logfile(const char *logfile_name)
{
    int filedesc = open(logfile_name, O_WRONLY | O_CREAT | O_APPEND, 0777);
    if (filedesc < 0)
        return ERROR;

    close_logfile();
    fd = filedesc;
    return OK;
}


void close_logfile(void)
{
    if (fd > 0)
        close(fd);
}
