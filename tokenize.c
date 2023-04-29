#include "headers.h"

int token_count(char *str, char *delim);
int token_len(char *str, char *delim);
char **_strtok(char *line, char *delim);

/**
 * token_count - counts number of delimi
 *                words within a string.
 * @str: string to be searched.
 * @delim: The delim char.
 *
 * Return: num of words contained within str.
 */
int token_count(char *str, char *delim)
{
	int index, tokens = 0, len = 0;

	for (index = 0; *(str + index); index++)
		len++;

	for (index = 0; index < len; index++)
	{
		if (*(str + index) != *delim)
		{
			tokens++;
			index += token_len(str + index, delim);
		}
	}

	return (tokens);
}

/**
 * token_len - finds the delim index marking the end
 *             of 1st token contained in a string.
 * @str: string to be searched.
 * @delim: delim char.
 *
 * Return: The delim index marking end of
 *         intitial token pointed by str.
 */
int token_len(char *str, char *delim)
{
	int index = 0, len = 0;

	while (*(str + index) && *(str + index) != *delim)
	{
		len++;
		index++;
	}

	return (len);
}

/**
 * _strtok - tokenizes a string.
 * @line: the string.
 * @delim: the delim char to tokenize.
 *
 * Return: A pointer to an array with tokenized words.
 */
char **_strtok(char *line, char *delim)
{
	char **ptr;
	int index = 0, tokens, t, a, l;

	tokens = token_count(line, delim);
	if (tokens == 0)
		return (NULL);

	ptr = malloc(sizeof(char *) * (tokens + 2));
	if (!ptr)
		return (NULL);

	for (t = 0; t < tokens; t++)
	{
		while (line[index] == *delim)
			index++;

		a = token_len(line + index, delim);

		ptr[t] = malloc(sizeof(char) * (a + 1));
		if (!ptr[t])
		{
			for (index -= 1; index >= 0; index--)
				free(ptr[index]);
			free(ptr);
			return (NULL);
		}

		for (l = 0; l < a; l++)
		{
			ptr[t][l] = line[index];
			index++;
		}

		ptr[t][l] = '\0';
	}
	ptr[t] = NULL;
	ptr[t + 1] = NULL;

	return (ptr);
}
