/* Name: Matthew Bichay
 * Course: Systems Development in the Unix Environment
 * Semester: Fall 2017
 * Description: Source file for the log_mgr library. Provides implementation
 * details for the log_event, set_logfile, and close_logfile methods.
 */

#include <unistd.h>
#include <fcntl.h>
#include <ctime>
#include <stdarg.h>
#include <cstdarg>
#include <cstdio>
#include <log_mgr.h>

// Base initialization of the first file descriptor
int fd = ERROR;


/* log_event takes a enumeration of different log levels, a string (capable of
 * inserting formatting options), and potential formatting options. The string
 * format will be used and will be logged to the current logfile.
 */
int log_event(Levels l, const char *fmt, ...)
{
    /* If fd is not initialized, set it to the default 'logfile' file, file
     * prints in the current directory
     */
    if (fd < 0)
    {   std::string file = "logfile";
        if (set_logfile(file.c_str()) < 0)
            return ERROR;
    }

    /* Parse time from time() method and localtime() */
   	time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];
    time (&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer,sizeof(buffer),"%m %d %I:%M:%S %Y",timeinfo);
    std::string time_str(buffer);

    /* Parse formatted arguments */
	va_list args;
	va_start(args, fmt);

    /* create buffer and write formatted string to buffer */
	char formatted_string[1000];
	vsprintf(formatted_string, fmt, args);

    /* convert char* to std::string for convenience purposes */
	std::string fmt_string = time_str + ":" + std::string(LEVEL_STRINGS[l]) + ":" + std::string(formatted_string) + "\n";

    /* If all characters were written, return ok, otherwise return error */
    if (write(fd, fmt_string.c_str(), fmt_string.length()) == fmt_string.length())
    {
        return OK;
    }
    return ERROR;
}


/* set_logfile takes a longfile pah, opens the file, closes the previous
 * logfile, and updates the global file descriptor for the logging environment
 */
int set_logfile(const char *logfile_name)
{
    int filedesc = open(logfile_name, O_WRONLY | O_CREAT | O_APPEND | O_SYNC, 0777);
    if (filedesc < 0)
        return ERROR;

    close_logfile();
    fd = filedesc;
    return OK;
}

/* close_logfile closes the logfile if a logfile has been opened */
void close_logfile(void)
{
    if (fd > 0)
        close(fd);
}
