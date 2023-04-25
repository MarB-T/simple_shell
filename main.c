#include "headers.h"

/**
 * main - program to run a custuom simple shell
 * @ac: argument count
 * @av: argument vector
 * Return: 0(success) -1(fail)
 */

int main(int ac, char **av)
{
	char *prompt = "simple_shell$ ";
	char *inputstr = NULL;
	char **argv = NULL;
	size_t len = 0;
	ssize_t num_of_chars;
	(void)ac;
	(void)av;

	while (1)
	{
		if (feof(stdin))
			break;
		printf("%s", prompt);
		num_of_chars = _getline(&inputstr, &len, stdin);
		if (num_of_chars == -1)
			return (-1);
		parsing_arg(inputstr, num_of_chars, &argv);
		process_command(argv);
	}

	free(inputstr);
	return (0);
}
