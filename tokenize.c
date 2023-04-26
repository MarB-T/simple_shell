#include "headers.h"

/**
 * _strtok - tokenize a string
 * @str: the string to tokenize
 * @delim: string of chars to be used as delimiters
 * Return: pointer to array of string tokens
 */

char **_strtok(char *str, const char *delim)
{
	char **tokens_ptr = NULL;
	int i = 0, tokens = 0, t, len, c = 0, j;

	if (str == NULL || delim == NULL)
		return (NULL);
	for (i = 0; *(str + i); i++)
	{
		if (*(str + i) == *delim)
		{
			tokens++;
		}
	}
	tokens_ptr = malloc(sizeof(char *) * (tokens + 2));
	if (tokens_ptr == NULL)
		return (NULL);
	for (t = 0; t < tokens; t++)
	{
		c = 0;
		while (*(str + c) && *(str + c) != *delim)
			c++;
		tokens_ptr[t] = malloc(sizeof(char) * (c + 1));
		if (tokens_ptr[t] == NULL)
		{
			for (i = 0; i < t; i++)
			{
				free(tokens_ptr[i]);
				free(tokens_ptr);
				return (NULL);
			}
		}
		for (j = 0; j < c; j++)
		{
			tokens_ptr[t][j] = str[j];
		}
		tokens_ptr[t][j] = '\0';
		str = str + c + 1;
	}
	tokens_ptr[t] = NULL;
	return (tokens_ptr);
}
