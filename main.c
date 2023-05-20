# include "libs.h"
/**
* main - entry code to simpe shell
* Return: 0.
**/
int main(void)
{
	int mode = isatty(STDIN_FILENO);

	if (mode != 1)
		sh_passive();
	else
		sh_active();
	return (0);
}
