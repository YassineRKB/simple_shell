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

/**
 * sh_getPath - function to get full path filename of program
 * Return: string
*/
char *sh_getPath(void)
{
	char *path = NULL;
	char **env = environ;

	for (; *env != NULL; env++)
	{
		if (strncmp(*env, "PATH=", 5) == 0)
		{
			path = *env + 5;
			break;
		}
	}
	if (path == NULL)
		perror("PATH variable not found.\n"), exit(EXIT_FAILURE);
	return (path);
}

/**
 * sh_isvalid - func to check if program is present in path
 * @path: string path argument to iterate
 * @filename: pointer to the filename.
 * Return: 1 on success, 0 on fail.
*/

int sh_isvalid(char *path, char **filename)
{
	int isvalid = 0;
	char *pathcopie = strdup(path);
	char *token = strtok(pathcopie, ":");
	char fullpath[BUFFSIZE] = "";

	do {
		snprintf(fullpath, sizeof(fullpath), "%s/%s", token, *filename);
		if (access(fullpath, F_OK) != -1)
		{
			*filename = strdup(fullpath);
			isvalid = 1;
			break;
		}
		token = strtok(NULL, ":");
	} while (token);
	free(pathcopie);
	return (isvalid);
}
