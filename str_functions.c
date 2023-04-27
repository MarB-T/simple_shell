#include "headers.h"

/**
 * _strlen - determine length of a string
 * @s: String whose length to find
 * Return: string lenght
 */

int _strlen(char *s)
{
	int len = 0;

	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

/**
 * _strcat - Function to concatenate two strings
 * @dest: First string
 * @src: Second string
 * Return: char pointer
 */

char *_strcat(char *dest, char *src)
{
	int index = 0;
	int dest_len = 0;

	while (dest[index++])
	{
		dest_len++;
	}
	for (index = 0; src[index]; index++)
	{
		dest[dest_len++] = src[index];
	}
	return (dest);
}

/**
 * *_strcpy - Copies a string including the termination character
 * @dest: Destination of string
 * @src: Source of the string
 * Return: string
 */

char *_strcpy(char *dest, char *src)
{
	char *dest_start = dest;

	while (*src != '\0')
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
	return (dest_start);
}

/**
 * _strcmp - Compares two strings
 * @s1: string 1
 * @s2: string 2
 * Return: their difference 0 if same
 */

int _strcmp(char *s1, char *s2)
{
	while ((*s1 && *s2) && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * _strdup - duplicates a string
 * @str: string to be duplicated
 * Return: pointer to string copied
 */

char *_strdup(char *str)
{
	unsigned int len, i;
	char *cpy;

	if (str == NULL)
		return (NULL);

	for (len = 0; str[len] != '\0'; len++)

	cpy = (char *)malloc(sizeof(char) * (len + 1));

	if (cpy == NULL)
		return (NULL);
	for (i = o; i <= len; i++)
	{
		cpy[i] = str[i];
	}
	return (cpy);
}

