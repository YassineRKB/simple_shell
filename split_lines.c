#include "libs.h"
/**
 * split_lines - tokenizer function
 * @line: string to tokenize
 * @delim: delimeters
 * Return: pointer to tokens.
*/
char **split_lines(char *line, char *delim)
{
	int bufsize = BUFFSIZE, oldsize;
	int i = 0;
	char **tokens = malloc(sizeof(char *) * bufsize);
	char *token;

	if (!tokens)
	{
		free(tokens);
		perror("Tokens Error");
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
			oldsize = sizeof(bufsize);
			bufsize += bufsize;
			tokens = _realloc(tokens, oldsize, sizeof(char *) * bufsize);
			if (!tokens)
			{
				perror("Error");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, delim);
	} while (token);
	tokens[i] = NULL;
	return (tokens);
}

/**
 * split_lines_file - tokenizer function
 * @line: string to tokenize
 * Return: pointer to tokens.
*/
char **split_lines_file(char *line)
{
	int bufsize = BUFFSIZE, oldsize;
	int i = 0;
	char **tokens = malloc(sizeof(char *) * bufsize);
	char *token;

	if (!tokens)
	{
		perror("Tokens Error");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, ";\n");
	while (token)
	{
		if (token[0] == '#')
			break;
		tokens[i] = token;
		i++;
		if (i >= bufsize)
		{
			oldsize = sizeof(bufsize);
			bufsize += bufsize;
			tokens = _realloc(tokens, oldsize, sizeof(char *) * bufsize);
			if (!tokens)
			{
				perror("Error");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, ";\n");
	}
	tokens[i] = NULL;
	return (tokens);
}
