#include "headers.h"

/**
 * exit_bulitin - function that checks
 * for inbuilt exit
 * @args: pointer to array of arguments
 *
 */

void exit_bulitin(char **args)
{
	int stat = 0, i = 0;

	if (args[i] != NULL)
	{
		while (args[i] != '\0')
		{
			if (args[i] >= '0' && args[i] <= '9')
			{
				stat = stat * 10 + (args[i] - '0');
			}
			else
			{
				write(STDERR_FILENO, "exit", 22);
				write(STDERR_FILENO, args[i], _strlen(args[i]));
				write(STDERR_FILENO, "\n", 1);
				free(args);
				exit(2);
			}
		}
	}
	free(args);
	exit(stat);
}
