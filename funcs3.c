#include "libs.h"
/**
* _strncpy - function that copies a string.
* @src: source inpt
* @dest: destination string
* @n: n bytes
* Return: char
**/
char *_strncpy(char *dest, char *src, int n)
{
	int len = 0;

	while (src[len] != '\0' && len < n)
	{
		dest[len] = src[len];
		len++;
	}

	while (len != n)
	{
		dest[len++] = '\0';
	}
	return (dest);
}

/**
* _strncmp - function that compares two strings.
* @s1: first string
* @s2: second string
* @n: n first char to compare
* Return: int
**/
int _strncmp(char *s1, char *s2, int n)
{
	int r, i = 0;

	for (; i < n; i++)
	{
		if (s1[i] != s2[i])
		{
			r = s1[i] - s2[i];
			return (r);
		}

		if (s1[i] == '\0')
			return (0);
	}
	return (0);
}
