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
			free(line);
			write(1, "$\n", 2);
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(line);
			perror("Error");
			write(1, "$\n", 2);
			exit(EXIT_FAILURE);
		}
	}
	return (line);
}
/**
 * read_stream - func to read line from stream.
 * Return: pointer to line.
*/

char *read_stream(void)
{
	int c, i = 0;
	int bufSIZE = BUFFSIZE;
	char *line = malloc(sizeof(char) * bufSIZE);

	if (!line)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		c = getchar();
		if (c == EOF)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		else if (c == '\n' || c == ';' || c == '&')
		{
			line[i] = '\0';
			return (line);
		}
		else
			line[i] = c;
		i++;
		if (i >= bufSIZE)
		{
			bufSIZE += bufSIZE, line = realloc(line, bufSIZE);
			if (!line)
			{
				perror("Error"), exit(EXIT_FAILURE);
			}
		}
	}
}
