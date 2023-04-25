#include "headers.h"

/**
 * update_line_ptr - append read input to line pointer
 * @ptr: mem reserved for input string
 * @buf: buffer containing read chars
 * @n: size allocated to mem reserved for input string
 * @input: size of read string
 */

void update_line_ptr(char **ptr, char *buf, size_t *n, ssize_t input)
{
	if (*ptr == NULL)
	{
		if (input > 120)
			*n = input;
		else
			*n = 120;
		*ptr = buf;
	}
	else if ((ssize_t)*n < input)
	{
		if (input > 120)
			*n = input;
		else
			*n = 120;
		*ptr = buf;
	}
	else
	{
		_strcpy(*ptr, buf);
		free(buf);
	}
}
/**
 * _realloc - reallocates memory
 * @old_mem: memory to be reallocated
 * @new: size of new memory
 * @old: size of old
 * Return: nothing
 *
 */

void *_realloc(void *old_mem, unsigned int nw, unsigned int old)
{
	void *new_mem;
	char *copy, *f;
	unsigned int i;

	if (old == nw)
		return (old_mem);
	if (nw == 0 && old_mem)
	{
		free(old_mem);
		return (NULL);
	}
	if (old_mem == NULL)
	{
		new_mem = malloc(nw);
		if (!new_mem)
			return (NULL);
		return (new_mem);
	}
	copy = old_mem;
	new_mem = malloc(sizeof(*copy) * nw);
	if (new_mem == NULL)
	{
		free(old_mem);
		return (NULL);
	}
	f = new_mem;
	for (i = 0; i < old && i < nw; i++)
		f[i] = *copy++;
	free(old_mem);
	return (new_mem);
}

/**
 * _getline - gets a stream of input data
 * @line_ptr: string of read input
 * @n: size of input
 * @stream: source of input
 * Return: size of read input
 */

ssize_t _getline(char **line_ptr, size_t *n, FILE *stream)
{
	static ssize_t input;
	char *buf, c = 'q';
	int r;

	if (input == 0)
		fflush(stream);
	else
		return (-1);
	input = 0;

	buf = malloc(sizeof(char) * 120);
	if (!buf)
		return (-1);
	while (c != '\n')
	{
		r = read(STDIN_FILENO, &c, 1);
		if (r == -1 || (r == 0 && input == 0))
		{
			free(buf);
			return (-1);
		}
		if (input && r == 0)
		{
			input++;
			break;
		}
		if (input >= 120)
		{
			buf = _realloc(buf, input, input + 1);
		}
		buf[input] = c;
		input++;
	}
	buf[input] = '\0';
	update_line_ptr(line_ptr, buf, n, input);

	return (input);
}
