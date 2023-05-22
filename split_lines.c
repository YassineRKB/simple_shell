#include "libs.h"
/**
 * split_lines - tokenizer function
 * @line: string to tokenize
 * Return: pointer to tokens.
*/
char **split_lines(char *line,char *delim)
{
	int bufsize = BUFFSIZE;
	int i = 0;
	char **tokens = malloc(sizeof(char *) * bufsize);
	char *token;

	if (!tokens)
	{
		free(tokens);
		printf("Tokens Error");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, delim);
	do {
		if (token[0] == '#')
			break;
		tokens[i] = token;
		i++;
		if (i >= bufsize)
		{
			bufsize += bufsize;
			tokens = realloc(tokens, sizeof(char *) * bufsize);
			if (!tokens)
			{
				printf("Error");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, delim);
	} while (token);
	tokens[i] = NULL;
	return (tokens);
}
