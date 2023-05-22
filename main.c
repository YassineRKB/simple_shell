#include "libs.h"
/**
 * main - simple shell entry point
 * @argc: arguments counter
 * @argv: arguments pointer
 * Return: 0
 * **/
int main(int argc, char **argv)
{
	int mode = isatty(STDIN_FILENO);
	(void)argv;

	if (mode != 1)
		sh_passive();
	else
	{
		if (argc == 2)
			sh_file(argv[1]);
		else
			sh_active();
	}
	return (0);
}
