
/**
 * process_command - processes the command and arguments passed
 * @agv: array of strings with lead by command followed by arguments
 * Return: error code (int)
 */

int process_command(char **argv)
{
	pid_t child_p = fork();

	if (child_p < 0)
	{
		printf("Error: fork failed\n");
		exit(1);
	}
	else if (child_p == 0)
	{
		execvp(argv[0], argv);
		printf("Error: command not found\n");
		exit(1);
	}
	else
	{
		wait(NULL);
	}
	return (0);
}
