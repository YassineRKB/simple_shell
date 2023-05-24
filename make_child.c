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
	char *path = sh_getEnv("PATH=");
	char *filename = args[0];

	isvalid = sh_isvalid(path, &filename);
	if (isvalid == 1)
	{
		args[0] = filename;
		pid = fork();
		if (pid == 0)
		{
			execve(args[0], args, environ);
			exit(EXIT_SUCCESS);
		}
		/* else if (pid < 0)
		{
			perror("cant make child");
			exit(EXIT_FAILURE);
		} */
		else	
		{
			waitpid(pid, &status, 0);
		}
		free(filename);
	}
	else
		sh_err("./hsh: No such file or directory\n\0");
	return (-1);
}

/**
 * sh_getEnv - function to get full path filename of program
 * @envVar: env var name
 * Return: string
*/
char *sh_getEnv(char *envVar)
{
	char *path = NULL;
	char **env = environ;
	size_t len = _strlen(envVar);

	for (; *env != NULL; env++)
	{
		if (_strncmp(*env, envVar, len) == 0)
		{
			path = *env + len;
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
	char *pathcopie = _strdup(path);
	char *token = strtok(pathcopie, ":");
	char *fullpath;
	size_t len;
	/* char fullpath[BUFFSIZE] = ""; */

	do {
		len = _strlen(token) + _strlen("/") + _strlen(*filename) + 1;
		fullpath = malloc(sizeof(char) * len);
		if (!fullpath)
			perror("make child=> sh_isvalid : malloc");
		fullpath[0] = '\0';
		_strcat(fullpath, token);
		_strcat(fullpath, "/");
		_strcat(fullpath, *filename);
		_strcat(fullpath, "\0");
		/* snprintf(fullpath, sizeof(fullpath), "%s/%s", token, *filename); */
		if (access(fullpath, F_OK) != -1)
		{
			*filename = _strdup(fullpath);
			isvalid = 1;
			break;
		}
		token = strtok(NULL, ":");
	} while (token);
	free(fullpath);
	free(pathcopie);
	return (isvalid);
}
