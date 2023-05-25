#include "libs.h"
/**
 * _setenv - function to set env variable with new value
 * @envar: env var to update or create
 * @enval: value of envar
 * Return: -1 on success, 0 on fail
*/

int _setenv(const char *envar, const char *enval)
{
	size_t nlen = strlen(envar), vlen = strlen(enval), rlen, envlen = 0;
	char **env = environ, **nenviron, *nvar;

	rlen = nlen + vlen + 2;
	for (; *env; env++)
	{
		if (_strncmp(*env, envar, nlen) == 0 && (*env)[nlen] == '=')
		{
			nvar = malloc(sizeof(char) * rlen);
			if (!nvar)
			{
				sh_err("Failed to allocate memory\n\0");
				return (0);
			}
			nvar[0] = '\0', _strcat(nvar, envar), _strcat(nvar, "=");
			_strcat(nvar, enval), *env = nvar;
			return (-1);
		}
	}
	nvar = malloc(sizeof(char) * rlen);
	if (!nvar)
	{
		sh_err("Failed to allocate memory\n\0");
		return (0);
	}
	nvar[0] = '\0', _strcat(nvar, envar), _strcat(nvar, "=");
	_strcat(nvar, enval);
	while (*env != NULL && *(env + 1) != NULL)
		envlen++, env++;
	nenviron = malloc(sizeof(char *) * (envlen + 2));
	if (!nenviron)
	{
		sh_err("Failed to allocate memory\n\0"), free(nvar);
		return (0);
	}
	for (envlen = 0, env = environ; *env; envlen++, env++)
		nenviron[envlen] = *env;
	nenviron[envlen] = nvar, nenviron[envlen + 1] = NULL;
	(envlen > 0) ? free(environ), environ = nenviron : (environ = nenviron);
	return (-1);
}
