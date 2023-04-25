#include <string.h>
#include "headers.h"

/**
 * exec_builtin - checks if argument is
 * a builtin command
 * @args: pointer to an array of arguments
 *
 * Return: 1 if argument is built-in
 * 0 if argument is not built-in
 */

int exec_builtin(char **args)
{
	char **env;

	if (strcmp(args[0], "env") == 0)
	{
		*env = environ;
		while (*env)
		{
			printf("%s,\n", *env++);
		}
		return (1);
	}
	return (0);
}
