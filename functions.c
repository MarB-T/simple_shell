#include "headers.h"


/**
 * parsing_arg - handles arguments passed to "simple_shell"
 * @inputstr: the string to tokenize
 * @num_of_chars: number of chars in input string
 * @argv: pointer to where string tokens will be written
 * Return: 0(success) or error codes
 *
 */

int parsing_arg(char *inputstr, size_t num_of_chars, char ***argv)
{
	char *inputstr_cp;
	char *token = NULL;
	int tokens = 0, i = 0;
	char *delim = " \n";

	inputstr_cp = malloc(sizeof(char) * num_of_chars);
	if (inputstr_cp == NULL)
	{
		printf("Memeory allocation error\n");
		return (-1);
	}
	strcpy(inputstr_cp, inputstr);
	token = strtok(inputstr, delim);
	while (token != NULL)
	{
		tokens++;
		token = strtok(NULL, delim);
	}
	*argv = malloc(sizeof(char *) * tokens);
	if (*argv == NULL)
	{
		printf("Mem allocation error!\n");
		return (-1);
	}
	token = strtok(inputstr_cp, delim);
	for (i = 0; token != NULL; i++)
	{
		(*argv)[i] = malloc(sizeof(char) * strlen(token));
		if ((*argv)[i] == NULL)
		{
			printf("Mem allocation error\n");
			return (-1);
		}
		strcpy((*argv)[i], token);
		token = strtok(NULL, delim);
	}
	(*argv)[i] = NULL;
	printf("%s\n", (*argv)[0]);
	return (0);
}

/**
 * _getenv - Gets an environment variable
 * @name: name of environment variable to check
 * Return: pointer to sought env vaiable
 */

char *_getenv(const char *name)
{
	size_t name_len = strlen(name);
	char **env_var;

	for (env_var = environ; *env_var != NULL; env_var++)
	{
		if (strncmp(*env_var, name, name_len) == 0 && (*env_var)[name_len] == '=')
		{
			return (&(*env_var)[name_len + 1]);
		}
	}

	return (NULL);
}
