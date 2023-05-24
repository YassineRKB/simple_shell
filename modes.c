#include "libs.h"
/**
 * sh_active - interactive mode handle
 * Return: -1
 * **/
void sh_active(void)
{
	char *line;
	char **args;
	int status = -1;

	do {
		line = read_line();
		args = split_lines(line, _DELIM);
		if (!args[0])
		{
			free(line);
			free(args);
			continue;
		}
		status = execute_args(args);
		free(line);
		free(args);
		if (status >= 0)
			exit(status);
	} while (status == -1);
}

/**
 * sh_passive - non-interactive mode handle
 * Return: void
*/

void sh_passive(void)
{
	char *line;
	char **args;
	int status = -1;

	while (status == -1)
	{
		line = read_stream();
		args = split_lines(line, _DELIM);
		if (!args[0])
		{
			free(line);
			free(args);
			continue;
		}
		status = execute_args(args);
		free(line);
		free(args);
		if (status >= 0)
			exit(status);
	}
}

/**
 * sh_file - non-interactive mode handle
 * @argv: pointer to arguments.
 * Return: void
*/

void sh_file(char **argv)
{
	char *line, **lines, **args, *filename = argv[1];
	int status = 1, len = 0, fileDesc, checkRead;

	fileDesc = open(filename, O_RDONLY);
	if (fileDesc == -1)
		printf("Error Reading file %s", filename), exit(EXIT_FAILURE);

	while (status == 1)
	{
		line = malloc(sizeof(char *) * BUFFSIZE);
		if (!line)
			printf("Error malloc"), close(fileDesc), exit(EXIT_FAILURE);
		checkRead = read(fileDesc, line, 1024);
		if (checkRead == -1)
			printf("Error Reading %s", filename), close(fileDesc), exit(EXIT_FAILURE);
		if (checkRead > 0)
		{
			lines = split_lines_file(line);
			while (lines[len])
			{
				args = split_lines(lines[len], _DELIM);
				status = execute_args(args);
				len++;
			}
			free(line);
			free(args);
		}
		else
			status = 0;
		if (status <= 0)
			close(fileDesc), exit(status);
	}
}
