#include "libs.h"
/**
 * _setenv - builtin setenv equivalent of putenv
 * @args: pointer to the arguments
 * Return: -1 on success 0 on fail
*/
void _setenv(char *var, char *value)
{
	int i;
	char *varenv, *nameenv, **env = environ;

	for (i = 0; env[i]; i++)
	{
		varenv = _strdup(env[i]);
		nameenv = strtok(varenv, "=");
		if (_strcmp(nameenv, var) == 0)
		{
			free(env[i]);
			env[i] = infocpy(nameenv, value);
			free(varenv);
			return;
		}
		free(varenv);
	}
	env = _realloc(env, i, sizeof(char *) * (i + 2));
	env[i] = infocpy(var, value);
	env[i + 1] = NULL;
}

/**
 * builtin_cd - built in cd func
 * @args: target dir
 * Return: -1 on success 0 on fail.
*/
int builtin_cd(char **args)
{
	const char *oldDir, *homeDir;
	char currDir[BUFFSIZE];

	homeDir = sh_getEnv("HOME=");
	getcwd(currDir, sizeof(currDir));
	if (!args[1])
	{
		printf("Usage: cd [director]\n");
	}
	else
	{
		if (_strcmp(args[1], "--") != 0 && _strcmp(args[1], "-") != 0)
		{
			if (chdir(args[1]) != 0)
				perror("Error");
		}
		else
		{
			if (_strcmp(args[1], "-") == 0)
			{
				oldDir = sh_getEnv("OLDPWD=");
				if (chdir(oldDir) != 0)
					perror("Error");
			}
			if (_strcmp(args[1], "--") == 0)
			{
				if (chdir(homeDir) != 0)
					perror("Error");
				_setenv("OLDPWD", currDir);
			}
		}
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
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
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
		return (_atoi(args[1]));
	else
		return (0);
}
