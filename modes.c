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