#include "libs.h"
/**
 * make_child_as_is - forks new child process and runs args
 * @args: array of strings that has file and flags
 * Return: -1 on success, 0 on error.
*/
int make_child_as_is(char **args)
{
	pid_t pid;
	int status, isvalid = 0;
	char *filename = args[0];

	isvalid = 1;
	if (isvalid == 1)
	{
		args[0] = filename;
		pid = fork();
		if (pid == 0)
		{
			status = execve(args[0], args, environ);
			if (status == -1)
				return (0);
			exit(EXIT_FAILURE);
		}
		else if (pid < 0)
		{
			perror("cant make child");
			exit(EXIT_FAILURE);
		}
		else
			wait(NULL);
	}
	else
	{
		write(2, filename, _strlen(filename));
		perror(" command does not exist\n");
		return (0);
	}
	return (-102);
}
