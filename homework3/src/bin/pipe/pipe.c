/* Name: Matthew Bichay
 * Course: Systems Development in the Unix Environment
 * Semester: Fall 2017
 * Description: Main file for the pipe binary.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <iostream>
#include <vector>
#include <string.h>
#include "log_mgr.h"

#define NUM_TOKENS 10
using namespace std;

/* tokenize is a method created for convenience of parsing arguments into
 * a char array. This method takes a string, a char* pointer, and a max number
 * of tokens. The string will be tokenized and all tokens will be placed in the
 * char* array. The number of tokens is returned at the end of this method.
 */
int tokenize(string str, char ** tokens, int max_num_tokens)
{
    int num_tokens;
    tokens[0] = strtok(&str[0u], " \011");
    for (num_tokens=1; num_tokens<max_num_tokens; ++num_tokens)
    {
        tokens[num_tokens] = strtok(NULL, " \011");
        if (tokens[num_tokens] == NULL)
            break;
    }
    return num_tokens;
}

int main(int argc, char* argv[])
{
    /* Convert arguments into vector of strings */
    vector<string> params(argv+1, argv+argc);

    /* Check to see if arguments were properly entered */
    if (params.size() < 2)
    {
        log_event(FATAL, "Error:%s", " pipe requires two arguments");
        return -1;
    }
    log_event(INFO, "%s", "arguments parsed");

    /* Create pipe */
	int pfd[2];
	pipe (pfd);

    /* Create child 1 */
	switch (fork())
	{
	    case -1:
        log_event(FATAL, "Error:%s", "fork has failed");
		perror ("fork");
		return -1;

	    case 0:
        /* Change the stdout of the first child to standard in */
		close (1);
		dup (pfd[1]);
		close (pfd[0]), close (pfd[1]);

        /* Tokenize first parsed argument */
        char * token[NUM_TOKENS];
        int num_tokens = tokenize(params[0], token, NUM_TOKENS);

        /* Execute command, arguments, and exit */
		execvp (token[0], token);
		perror ("execlp");
		_exit(1);
	}
    /* Create child 2 */
	switch (fork())
	{
	    case -1:
        log_event(FATAL, "Error:%s", "fork has failed");
		perror ("fork");
		return -1;

	    case 0:
        /* Change the stdin to the first child's standard out */
		close (0);
		dup (pfd[0]);
		close (pfd[0]), close (pfd[1]);

        /* Tokenize second parsed argument */
        char * token[NUM_TOKENS];
        int num_tokens = tokenize(params[1], token, NUM_TOKENS);

        /*Execute command, arguments, and exit */
		execvp (token[0], token);
		perror ("execlp");
		_exit(1);
	}
    /* Close pipes */
	close (pfd[0]), close (pfd[1]);
	while (wait(NULL) != -1)
		;

    log_event(INFO, "%s", "commands have been executed");
    return 0;
}
