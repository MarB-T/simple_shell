#include "headers.h"
#include "functions.c"
#include "processing_command.c"

/**
 * main - program to run a custuom simple shell
 * @argc: argument count
 * @argv: argument vector
 * Return: 0(success) -1(fail)
 */

int main()
{
	char *prompt = "simple_shell$ ";
	char *inputstr = NULL;
	char **argv = NULL;
	size_t len = 0;
	ssize_t num_of_chars;
	int ret;

	(void)ret;

	while (1)
	{
		if (feof(stdin))
			break;
		printf("%s", prompt);
		num_of_chars = getline(&inputstr, &len, stdin);
		if (num_of_chars == -1)
			return (-1);
		parsing_arg(inputstr, num_of_chars, &argv);
		process_command(argv);
	}

	free(inputstr);
	return (0);
}
