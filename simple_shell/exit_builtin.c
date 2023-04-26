#include "headers.h"

/**
 * exit_bulitin - function that checks
 * for inbuilt exit
 * @args: pointer to array of arguments
 *
 */

void exit_bulitin(char *args)
{
	int stat;

	if (args == NULL)
	{
		stat = 0;
	}
	else
	{
		stat = atoi(args);
	}
	free(args);
	exit(stat);
}
