#include "libs.h"
/**
 * execute_args - func to check if comand is built in or look in path
 * @args: input to be checked
 * Return: -1 on success, 0+ on fail
*/

int execute_args(char **args)
{
	unsigned long int i = 0, cmdlen = 0;
	char *builtin_funcs_list[] = {
		"cd",
		"env",
		"setenv",
		"help",
		"exit"
	};
	int (*builtin_funcs[])(char **) = {
		&builtin_cd,
		&builtin_env,
		&builtin_setenv,
		&builtin_help,
		&builtin_exit
	};
	int flag = 0;

	cmdlen = sizeof(builtin_funcs_list) / sizeof(char *);
	for (; i < cmdlen; i++)
		if (_strcmp(args[0], builtin_funcs_list[i]) == 0)
			return ((*builtin_funcs[i])(args));

	if (_strstr(args[0], "/"))
		flag = make_child_as_is(args);
	else
		flag = make_child(args);
	return (flag);
}
