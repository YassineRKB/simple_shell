# include "libs.h"
# include <unistd.h>
/**
* sh_getEnv - function to get env var value.
* @env: target env variable
* Return: string on success.
**/
char *sh_getEnv(char *s)
{
	int i, j, status;

	for (i = 0; environ[i] != NULL; i++)
	{
		status = 1;
		for (j = 0; environ[i][j] != '='; j++)
		{
			if (s[j] != environ[i][j])
			{
				status = 0;
				break;
			}
		}
		if (status)
			return (&environ[i][j]);
	}
	return (NULL);
}
