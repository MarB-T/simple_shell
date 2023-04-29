#include "headers.h"

int file_cmds(char *file_path, int *exe_ret);
int cant_open(char *file_path);

/**
 * cant_open - If file doesn't exist or doesn't have proper permissions.
 * @file_path: path to the file.
 *
 * Return: 127.
 */

int cant_open(char *file_path)
{
	char *err, *hist_str;
	int len;

	hist_str = _itoa(hist);
	if (!hist_str)
		return (127);

	len = _strlen(name) + _strlen(hist_str) + _strlen(file_path) + 16;
	err = malloc(sizeof(char) * (len + 1));
	if (!err)
	{
		free(hist_str);
		return (127);
	}

	_strcpy(err, name);
	_strcat(err, ": ");
	_strcat(err, hist_str);
	_strcat(err, ": Can't open ");
	_strcat(err, file_path);
	_strcat(err, "\n");

	free(hist_str);
	write(STDERR_FILENO, error, len);
	free(err);
	return (127);
}

/**
 * file_cmds - takes a file and attempts to run commands stored
 *
 * @file_path: path to the file.
 * @exe_ret: return value of last executed command.
 *
 * Return: If file can't be opened - 127.
 *	   If malloc fails - -1.
 *	   Else return value of the last command ran.
 */
int file_cmds(char *file_path, int *exe_ret)
{
	ssize_t file, b_read, i;
	unsigned int line_size = 0;
	unsigned int old_size = 120;
	char *line, **args, **front;
	char buff[120];
	int ret;

	hist = 0;
	file = open(file_path, O_RDONLY);
	if (file == -1)
	{
		*exe_ret = cant_open(file_path);
		return (*exe_ret);
	}
	line = malloc(sizeof(char) * old_size);
	if (!line)
		return (-1);
	do {
		b_read = read(file, buff, 119);
		if (b_read == 0 && line_size == 0)
			return (*exe_ret);
		buff[b_read] = '\0';
		line_size += b_read;
		line = _realloc(line, old_size, line_size);
		_strcat(line, buff);
		old_size = line_size;
	} while (b_read);
	for (i = 0; line[i] == '\n'; i++)
		line[i] = ' ';
	for (; i < line_size; i++)
	{
		if (line[i] == '\n')
		{
			line[i] = ';';
			for (i += 1; i < line_size && line[i] == '\n'; i++)
				line[i] = ' ';
		}
	}
	var_replacement(&line, exe_ret);
	handle_line(&line, line_size);
	args = _strtok(line, " ");
	free(line);
	if (!args)
		return (0);
	if (check_args(args) != 0)
	{
		*exe_ret = 2;
		free_args(args, args);
		return (*exe_ret);
	}
	front = args;

	for (i = 0; args[i]; i++)
	{
		if (_strncmp(args[i], ";", 1) == 0)
		{
			free(args[i]);
			args[i] = NULL;
			ret = call_args(args, front, exe_ret);
			args = &args[++i];
			i = 0;
		}
	}

	ret = call_args(args, front, exe_ret);

	free(front);
	return (ret);
}
