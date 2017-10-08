#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <iostream>
#include <vector>
#include <string.h>

#define NUM_TOKENS 10
using namespace std;


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
    vector<string> params(argv+1, argv+argc);
    if (!params.size() || params.size() > 2)
        return -1;
    
    char * token[NUM_TOKENS];
    int num_tokens = tokenize(params[0], token, NUM_TOKENS);

	int pfd[2];
	pipe (pfd);
	switch (fork())
	{
	    case -1:
		perror ("fork");
		return -1;
	    case 0:		/* child */
		close (1);
		dup (pfd[1]);
		close (pfd[0]), close (pfd[1]);  
        char * token[NUM_TOKENS];
        int num_tokens = tokenize(params[0], token, NUM_TOKENS);
		execvp (token[0], token);
		perror ("execlp");
		_exit(1);
	}
	switch (fork())
	{
	    case -1:
		perror ("fork");
		return -1;
	    case 0:		/* child */
		close (0);
		dup (pfd[0]);
		close (pfd[0]), close (pfd[1]);
        char * token[NUM_TOKENS];
        int num_tokens = tokenize(params[1], token, NUM_TOKENS);
		execvp (token[0], token);
		perror ("execlp");
		_exit(1);
	}
	close (pfd[0]), close (pfd[1]);

	while (wait(NULL) != -1)
		;
    return 0;
}
