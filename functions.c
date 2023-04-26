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
	char *inputstr_cp, *token = NULL, *delim = " \n";
	int tokens = 0, i = 0;

	inputstr_cp = malloc(sizeof(char) * num_of_chars);
	if (inputstr_cp == NULL)
		error_msg(99);
	_strcpy(inputstr_cp, inputstr);
	token = strtok(inputstr, delim);
	while (token != NULL)
	{
		tokens++;
		token = strtok(NULL, delim);
	}
	*argv = malloc(sizeof(char *) * tokens);
	if (*argv == NULL)
		error_msg(99);
	token = strtok(inputstr_cp, delim);
	for (i = 0; token != NULL; i++)
	{
		(*argv)[i] = malloc(sizeof(char) * _strlen(token));
		if ((*argv)[i] == NULL)
			error_msg(99);
		_strcpy((*argv)[i], token);
		token = strtok(NULL, delim);
	}
	(*argv)[i] = NULL;
	if (*argv[0] != NULL)
	{
		if (_strcmp(*argv[0], "exit") == 0)
		{
			shell_exit();
		}
	}
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

/**
 * shell_exit - exits a program
 *
 * Return: 0
 */

void shell_exit(void)
{
	exit(0);
}

/**
 * error_msg - handles error messages
 * @error_code: error code
 * Return: nothing
 *
 */

void error_msg(int error_code)
{
	switch (error_code)
	{
		case 99:
			perror("Memory allocation error");
			exit(0);
	}
}
