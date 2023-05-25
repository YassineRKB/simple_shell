#include "libs.h"
/**
* _strcmp - function that compares two strings.
* @s1: first string
* @s2: second string
* Return: int
**/
int _strcmp(char *s1, char *s2)
{
	int i, r;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	r = s1[i] - s2[i];
	return (r);
}

/**
* _memcpy - function that copies memory area.
* @dest: pointer to destination memory area.
* @src: pointer to source memory area
* @n: n bytes.
* Return: destination pointer.
**/
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}

/**
* _realloc - function that reallocates a memory block using malloc and free
* @ptr: pointer's memory to reallocat
* @old_size: size of pointer allocated memory
* @new_size: size of new allocated memory
* Return: pointer, NULL
**/

void *_realloc(void *ptr, int old_size, int new_size)
{
	char *p, *pp;
	int i;

	if (ptr == NULL)
	{
		pp = malloc(new_size);
		if (pp == NULL)
			return (NULL);
		free(ptr);
		return (pp);
	}
	if (new_size == old_size)
		return (ptr);

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	p = malloc(new_size);
	if (p == NULL)
		return (NULL);
	pp = ptr;
	for (i = 0; i < old_size; i++)
	{
		p[i] = pp[i];
	}
	free(ptr);
	return (p);
}

/**
* _strcat - function
* @src: source string
* @dest: destination string
* Return: pointer
**/
char *_strcat(char *dest, const char *src)
{
	int len = 0;
	int i;

	while (dest[len] != '\0')
	{
		len++;
	}

	i = 0;
	while (src[i] != '\0')
	{
		dest[len] = src[i];
		len++;
		i++;
	}
	return (dest);
}
