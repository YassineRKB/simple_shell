#include "libs.h"
/**
* sh_getInput - gets input from pointer and assign content to memory
* @input: pointer to input.
* Return: int Read status of input
**/
int sh_getInput(char **input)
{
	int checkRead = 1;

	*input = malloc(SH_BUFFER);
	checkRead = read(STDIN_FILENO, *input, SH_BUFFER);
	for (; **input == ' '; checkRead--, (*input)++)
		;
	return (checkRead);
}

/**
* sh_runCmd - runs commands and executes programs.
* @av: pointer to arguments
* Return: 0 on success, -1 on fail.
**/
/*int sh_runCmd(char *input)
{
	char *pathname, *params, *location;

	if (execve(NULL, NULL, NULL) == -1)
	{
		return (-1);
	}

	return (0);
}
*/
