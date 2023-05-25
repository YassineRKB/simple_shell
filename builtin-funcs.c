#include "libs.h"
/**
 * builtin_cd - built in cd func
 * @args: target dir
 * Return: -1 on success 0 on fail.
*/
int builtin_cd(char **args)
{
	char *oldDir, *homeDir;
	char currDir[BUFFSIZE];

	homeDir = sh_getEnv("HOME=");
	getcwd(currDir, sizeof(currDir));
	if (!args[1])
	{
		perror("Usage: cd [director]\n");
	}
	else
	{
		if (_strcmp(args[1], "--") != 0 && _strcmp(args[1], "-") != 0)
		{
			if (chdir(args[1]) != 0)
				perror("Error");
			_setenv("OLDPWD", currDir);
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
	char *st1 = "help: simple shell \n";
	char *st2 = "Type a command then its arguments: for more info\n";
	char *st3 = "man [command].\n";
	char *st4 = "Built-in commands:\n";
	char *st5 = " cd\n";
	char *st6 = " env\n";
	char *st7 = " help";
	char *st8 = " exit\n";
	(void)(**args);

	/* cmdlen = sizeof(builtin_funcs_list) / sizeof(char *); */
	write(1, st1, _strlen(st1));
	write(1, st2, _strlen(st2));
	write(1, st3, _strlen(st3));
	write(1, st4, _strlen(st4));
	write(1, st5, _strlen(st4));
	write(1, st6, _strlen(st4));
	write(1, st7, _strlen(st4));
	write(1, st8, _strlen(st4));
	return (-1);
}

/**
 * builtin_exit - builtin exit func
 * @args: arguments.
 * Return: 0
*/
int builtin_exit(char **args)
{
	int code;

	if (args[1])
	{
		code = _atoi(args[1]);
		exit(code);
		return (1);
	}
	else
		return (0);
}

/**
 * builtin_setenv - builtin shell set env
 * @args: arguments
 * Return: -1 on success, 0 on fail
*/
int builtin_setenv(char **args)
{
	if (args[1] && args[2])
		_setenv(args[1], args[2]);
	else
		sh_err("setenv VARIABLE VALUE\n\0");
	return (-1);
}
