#include "headers.h"

/**
 * exit_bulitin - function that checks
 * for inbuilt exit
 * @args: pointer to array of arguments
 *
 */

void exit_bulitin(char **args)
{
	int stat = 0;

	if (args[i] != NULL)
	{
		stat = atoi(args);
	}
	free(args);
	exit(stat);
}
