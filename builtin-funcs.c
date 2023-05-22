#include "libs.h"
/**
 * builtin_cd - built in cd func
 * @args: target dir
 * Return: -1 on success 0 on fail.
*/
int builtin_cd(char **args)
{
	if (!args[1])
	{
		perror("Error");
		return (0);
	}
	else
	{
		if (chdir(args[1]) != 0)
			perror("Error");
	}
	return (-1);
}

/**
 * builtin_env - builtin env func
 * @args: arguments
 * Return: -1 on success, 0 on error.
*/
int builtin_env(char **args)
{
	int i = 0;
	(void) (**args);

	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (-1);
}

/**
 * builtin_help - builtin help function
 * @args: arguments
 * Return: -1 on success, 0 on fail
*/
int builtin_help(char **args)
{
	unsigned long int i = 0, cmdlen = 0;
	char *builtin_funcs_list[] = {
		"cd",
		"env",
		"help",
		"exit"
	};
	(void)(**args);

	cmdlen = sizeof(builtin_funcs_list) / sizeof(char *);

	printf("help: simple shell \n");
	printf("Type a command then its arguments, if in doubt access man page:\n");
	printf("man [command].\n");
	printf("Built-in commands\n");
	for (; i < cmdlen; i++)
		printf(" %s\n", builtin_funcs_list[i]);
	return (-1);
}

/**
 * builtin_exit - builtin exit func
 * @args: arguments.
 * Return: 0
*/
int builtin_exit(char **args)
{
	if (args[1])
		return (atoi(args[1]));
	else
		return (0);
}
