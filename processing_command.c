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

	command = get_location(argv[0]);
	if (!command)
	{
		write(STDERR_FILENO, "Error:Command not found\n", 24);
		return (1);
	}

	if (child_p < 0)
	{
		perror("Error: fork failed\n");
		exit(1);
	}
	else if (child_p == 0)
	{
/*		env = _copyenv(); */
		if (execve(command, argv, environ) == -1)
		{
			perror("Error: command not found\n");
			exit(1);
		}
	}
	else
	{
		wait(NULL);
	}

	if (command != argv[0])
	{
		free(command);
	}
	return (0);
}
