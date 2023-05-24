#include "libs.h"
/**
 * sh_err - function to print errors
 * @msg: string containing the message
 * Return: void
*/

void sh_err(char *msg)
{
	size_t len;
	char *fullmsg, *sepa = ": ";

	len = _strlen(sepa) + _strlen(msg);
	fullmsg = malloc(sizeof(char *) * len);
	if(!fullmsg)
		perror("malloc");
	fullmsg[0] = '\0';
	_strcat(fullmsg, sepa);
	_strcat(fullmsg, msg);
	write(2, msg, len);
	free(fullmsg);
}