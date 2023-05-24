#include "libs.h"
/**
 * sh_getline - gets input from stdin
 * @line: pointer to the line.
 * @n: size of the buffer
 * @stream: stdin stream
 * Return: line, 0 to 1 on error
*/
int sh_getline(char **line, int *n, FILE *stream)
{
	char buffer[BUFFSIZE], *newline;
	int checkRead, len = 0, oldsize;

	*line = NULL;
	write(1, "$ ", 2);
	if (line == NULL || stream == NULL || n == NULL)
		exit(EXIT_FAILURE);
	while ((checkRead = read(fileno(stream), buffer, sizeof(buffer))) > 0)
	{
		if (len + checkRead + 1 > *n)
		{
			oldsize = *n;
			*n = (*n == 0) ? checkRead + 1 : *n * 2;
			newline = _realloc(*line, oldsize, *n);
			if (newline == NULL)
				perror("error"), exit(EXIT_FAILURE);
			*line = newline;
		}
		_memcpy(*line + len, buffer, checkRead);
		len += checkRead;
		if (buffer[checkRead - 1] == '\n')
			break;
	}
	if (checkRead == 0 && len == 0)
	{
		write(1, "\n", 1);
		exit(EXIT_SUCCESS);
	}
	if ((len > 0) && (*line)[len - 1] == '\n')
		(*line)[len - 1] = '\0';
	else
		(*line)[len] = '\0';
	if (checkRead == -1)
	{
		perror("read");
		exit(EXIT_FAILURE);
	}
	return (0);
}

/**
 * _strdup - duplicates string
 * @originstr: string to be duplicated
 * Return: string
*/
char *_strdup(char *originstr)
{
	char *newstr;
	int originStrLen = 0;

	while (originstr[originStrLen])
		originStrLen++;

	newstr = malloc(originStrLen + 1);
	if (!newstr)
		return (0);
	_strcpy(newstr, originstr);
	return (newstr);
}

/**
 * _strcpy - function that copies string
 * @src: sting to be copied
 * @dest: destination
 * Return: nothing
*/
char *_strcpy(char *dest, char *src)
{
	int i;
	int len = 0;

	while (src[len] != '\0')
	{
		len++;
	}

	for (i = 0; i < len; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _atoi - function that converts string to int
 * @s: string to be converted
 * Return: converted number or 0
*/
int _atoi(char *s)
{
	int i = 0, n = 0, len = 0, j = 0, c = 0, d = 0;

	while (s[len] != '\0')
		len++;
	while (i < len && c == 0)
	{
		if (s[i] == '-')
			++j;
		if (s[i] >= '0' && s[i] <= '9')
		{
			d = s[i] - '0';
			if (j % 2)
				d = -d;
			n = n * 10 + d;
			c = 1;
			if (s[i + 1] < '0' || s[i + 1] > '9')
				break;
			c = 0;
		}
		i++;
	}
	if (c == 0)
		return (0);
	return (n);
}

/**
 * _strlen - function that retruns the lengh of a string.
 * @s: pointer.
 * Return: lenght of a string.
**/
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
