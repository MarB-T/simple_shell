#include <string.h>
#include "headers.h"

/**
 * env_builtin - checks if argument is
 * a builtin env command
 * @args: pointer to an array of arguments
 *
 * Return: 1 if argument is built-in
 * 0 if argument is not built-in
 */

int env_builtin(char **args)
{
	char **env;

	if (_strcmp(args[0], "env") == 0)
	{
		env = environ;
		while (*env)
		{
			write(STDOUT_FILENO, *env, _strlen(*env));
			write(STDOUT_FILENO, "\n", 1);
		}
		return (1);
	}
	return (0);
}
