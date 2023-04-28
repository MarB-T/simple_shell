#include "headers.h"

/**
 * _strchr - searches a char in a string
 * @s: the string to be searched
 * @c: the char to search
 * Return: the search char or NULL
 */
char *_strchr(const char *s, int c)
{
	while (*s != '\0' && *s != c)
		s++;
	if (*s == c)
		return ((char *)s);
	return (NULL);
}

/**
 * _strtok - tokenize a string
 * @str: the string to tokenize
 * @delim: string of chars to be used as delimiters
 * Return: pointer to array of string tokens
 */


char *_strtok(char *str, const char *delim)
{
	static char *last_token;
	char *token = NULL;
	int i, j;

	if (str != NULL)
		last_token = str;

/* skip leading delimiters */
	while (*last_token && _strchr(delim, *last_token))
		last_token++;

	if (!*last_token)
	{
		return (NULL);
	}

/* find the end of the token */
	token = last_token;
	for (i = 0; *last_token && !_strchr(delim, *last_token); i++)
		last_token++;

	if (i == 0)
	{
		return (_strtok(NULL, delim));
	}

/* remove trailing delimiters from the token */
	for (j = i - 1; j >= 0 && _strchr(delim, token[j]); j--)
		token[j] = '\0';

	return (token);
}

