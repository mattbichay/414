/* Name: Matthew Bichay
 * Course: Systems Development in the Unix Environment
 * Semester: Fall 2017
 * Description: Header file for the log_mgr library. Provides function
 * prototypes for the log_event, set_logfile, and close_logfile methods.
 */


#ifndef LOG_MGR
#define LOG_MGR

#include <string>

#define OK 0
#define ERROR -1

/* Logging Levels */
typedef enum {INFO, WARNING, FATAL} Levels;

/* Logging Level Strings */
static const char * LEVEL_STRINGS[] = { "INFO", "WARNING", "FATAL" };

/* Global File Descriptor */
extern int fd;

/* log_event takes a enumeration of different log levels, a string (capable of
 * inserting formatting options), and potential formatting options. The string
 * format will be used and will be logged to the current logfile.
 */
int log_event(Levels l, const char *fmt, ...);


/* set_logfile takes a longfile pah, opens the file, closes the previous
 * logfile, and updates the global file descriptor for the logging environment
 */
int set_logfile(const char *logfile_name);


/* close_logfile closes the logfile if a logfile has been opened */
void close_logfile(void);

#endif
