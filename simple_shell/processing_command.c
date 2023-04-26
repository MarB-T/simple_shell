#include "headers.h"
/**
 * process_command - processes the command and arguments passed
 * @argv: array of strings with lead by command followed by arguments
 * Return: error code (int)
 */

int process_command(char **argv)
{
	char *command = NULL;
	pid_t child_p = fork();

	if (child_p < 0)
	{
		perror("Error: fork failed\n");
		exit(1);
	}
	else if (child_p == 0)
	{
		command = get_location(argv[0]);
		if (execve(command, argv, NULL) == -1)
		{
			perror("Error: command not found\n");
			exit(1);
		}
	}
	else
	{
		wait(NULL);
	}
	return (0);
}
