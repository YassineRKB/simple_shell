#include "libs.h"
/**
 * make_child_as_is - forks new child process and runs args
 * @args: array of strings that has file and flags
 * Return: -1 on success, 0 on error.
*/
int make_child_as_is(char **args)
{
	pid_t pid;
	int status, isvalid = 0, state = -1;
	char *filename = args[0];

	isvalid = sh_isvalid_as_is(filename);
	if (isvalid == 1)
	{
		pid = fork();
		if (pid == 0)
		{
			execve(filename, args, environ);
			state = -102;
			exit(EXIT_SUCCESS);
		}
		else
		{
			waitpid(pid, &status, 0);
		}
	}
	else
	{
		sh_err("./hsh: No such file or directory\n\0");
	}

	return (state);
}

/**
 * sh_isvalid_as_is - a function to check if raw input
 * is a valid path.
 * @filename: input to be checked
 * Return: 0 on fail and 1 on success
*/
int sh_isvalid_as_is(char *filename)
{
	int isvalid = 0;

	if (access(filename, F_OK) != -1)
		isvalid = 1;
	return (isvalid);
}
