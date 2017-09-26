#ifndef LOG_MGR
#define LOG_MGR

#include <string>

#define OK 0
#define ERROR -1

typedef enum {INFO, WARNING, FATAL} Levels;
static const char * LEVEL_STRINGS[] = { "INFO", "WARNING", "FATAL" };
extern int fd;

int log_event(Levels l, const char *fmt, ...);

int set_logfile(const char *logfile_name);

void close_logfile(void);

#endif
