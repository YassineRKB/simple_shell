#include "libs.h"
/**
 * make_child - forks new child process and runs args
 * @args: array of strings that has file and flags
 * Return: -1 on success, 0 on error.
*/
int make_child(char **args)
{
	pid_t pid;
	int status, isvalid = 0;
	char *filename = "/usr/bin/ls";

	args[0] = filename;
	pid = fork();
	if (pid == 0)
	{
		status = execve(args[0], args, environ);
		if (status == -1)
			perror("Pid Error");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("cant make child");
		exit(EXIT_FAILURE);
	}
	else
		wait(NULL);
	return (-1);
}
