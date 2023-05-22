#include "libs.h"
/**
 * read_line - func to read input
 * Return: pointer that points to string.
*/
char *read_line(void)
{
	char *line = NULL;
	int status;
	int len = 0;

	status = getline(&line, &len, stdin);
	if (status == -1)
	{
		if (feof(stdin))
		{
			write(1, "$\n", 2);
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("Error");
			write(1, "$\n", 2);
			exit(EXIT_FAILURE);
		}
	}
	return (line);
}
