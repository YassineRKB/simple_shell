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
		status = execute_args(args);
		free(line);
		free(args);
		if (status >= 0)
			exit(status);
	}
}
