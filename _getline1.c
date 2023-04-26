#include "headers.h"

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	char *pos;
	char *end;
	ssize_t num_read = 0;
	int c;

	if (*lineptr == NULL || *n == 0)
	{
		*n = 128;
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
			return (-1);
	}
	pos = *lineptr;
	end = *lineptr + *n;
	while ((num_read = read(fileno(stream), pos, end - pos - 1)) > 0)
	{
		pos += num_read;
		c = *(pos - 1);
		if (c == '\n')
			break;
		if (pos >= end - 1)
		{
			*n *= 2;
			*lineptr = realloc(*lineptr, *n);
			if (*lineptr == NULL)
				return (-1);
			pos = *lineptr + (*n / 2);
			end = *lineptr + *n;
		}
	}
	if (num_read == 0 && pos == *lineptr)
		return (-1);
	if (num_read == -1)
		return (-1);
	*pos = '\0';
	return (pos - *lineptr);
}
