#include "libs.h"
/**
 * sh_err - function to print errors
 * @msg: string containing the message
 * Return: void
*/

void sh_err(char *msg)
{
	size_t len;
	char *filename = SHNAME, *fullmsg, sepa = ": ";

	len = _strlen(filename) + _strlen(sepa) + _strlen(msg) + 2;
	fullmsg[0] = '\0';
	_strcat(fullmsg, filename);
	_strcat(fullmsg, sepa);
	_strcat(fullmsg, msg);
	_strcat(fullmsg, "\n\0");
	write(2, msg, len);
}