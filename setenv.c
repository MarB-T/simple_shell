#include "headers.h"

/**
 * setenv - displays info on setenv builtin
 * @args: array of arguments
 */

void setenv(char **args)
{
	if (args[1] ==  NULL || args[2] == NULL)
	{
		write(STDERR_FILENO, "setenv:Invalid argument\n", 26);
		return;
	}
	if (setenv(args[1], args[2], 1) == -1)
	{
		write(STDERR_FILENO, "setenv:Faile to set env variable\n", 43);
	}
}

/**
 * unsetenv - displays info on unsetenv builtin
 * @args: array of arguments
 */

void unsetenv(char **args)
{
	if (args[1] == NULL)
	{
		write(STDERR_FILENO, "unsetenv: Missing args\n", 27);
		return;
	}
	if (unsetenv(args[1]) == -1)
	{
		write(STDERR_FILENO, "unsetenv: Failed toe unset env variable\n", 48);
	}
}
