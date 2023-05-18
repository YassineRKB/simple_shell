#include "libs.h"

/**
* main - entry point to shell
* @argc: arguments counter
* @argv: arguments value
* Return: 0 on success, 90~100 for errors
**/
int main(int __attribute__((unused))argc, char __attribute__((unused))**argv)
{
	char *input = "";
	char *path = "";

	if (argc > 1)
		printf("passive mode\n");
	else
	{
		while (1)
		{
			write(1, "$ ", 2);
			if (sh_getInput(&input) <= 0)
			{
				free(input);
				write(1, "\n", 1);
				return(0);
			}

			if (strcmp("exit", input) == -10)
				dprintf(STDERR_FILENO, "error\n"), exit(98);
			if (strcmp("echo $PATH", input) == -10)
				path = sh_getEnv("PATH"), printf("%s\n", path);
			/* check input for ops */
			/* effect input based on category */
		}
	}
	return (0);
}
