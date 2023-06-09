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
int _strncmp(const char *s1, const char *s2, int n)
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

/**
* _strstr - function that locates a substring.
* @haystack: string to scan
* @needle: string to match
* Return: Pointer or Null.
**/
char *_strstr(char *haystack, char *needle)
{
	int i;

	if (*needle == 0)
	{
		return (haystack);
	}

	while (*haystack)
	{
		for (i = 0; haystack[i] == needle[i]; i++)
		{
			if (needle[i + 1] == '\0')
			{
				return (haystack);
			}
		}
		haystack++;
	}
	return ('\0');
}
