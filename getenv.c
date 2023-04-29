#include "headers.h"

/**
 * _getenv - gets an env variable from the PATH.
 * @var: name of the env var.
 *
 * Return: If the env variable doesn't exist - NULL.
 *         else - pointer to the env variable.
 */

char **_getenv(const char *var)
{
	int i, len;

	len = _strlen(var);
	for (i = 0; environ[i]; i++)
	{
		if (_strncmp(var, environ[i], len) == 0)
			return (&environ[i]);
	}

	return (NULL);
}
