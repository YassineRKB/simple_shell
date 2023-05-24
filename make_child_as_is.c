#include "libs.h"
/**
 * make_child_as_is - forks new child process and runs args
 * @args: array of strings that has file and flags
 * Return: -1 on success, 0 on error.
*/
int make_child_as_is(char **args)
{
	pid_t pid;
	int status, state = 0;
	char *filename = args[0];

	args[0] = filename;
	pid = fork();
	if (pid == 0)
	{
		execve(args[0], args, environ);
		state = -102;
		exit(EXIT_SUCCESS);
	}
	else
	{
		waitpid(pid, &status, 0);
		make_child(args);
		state = -1;
	}

	return (state);
}
