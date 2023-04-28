#include "headers.h"

int _setenv(const char *name, const char *value, int overwrite)
{
	char **envp, *newenv, **newenvp;
	unsigned int environ_size = _strlen(*environ);
    /* Check if name or value is NULL */
    if ((name == NULL) || (value == NULL))
    {
        errno = EINVAL;
        return (-1);
    }

    /* Check if name is a valid environment variable name */
    if (_strchr(name, '=') != NULL) {
        errno = EINVAL;
        return -1;
    }

    /* Search for an existing environment variable with the given name */
    envp = environ;
    while (*envp != NULL) {
        if (_strncmp(*envp, name, _strlen(name)) == 0 && (*envp)[_strlen(name)] == '=') {
            /* An existing variable with the given name has been found */
            if (!overwrite) {
                /* Do not overwrite the variable if the overwrite flag is not set */
                return (0);
            }

            /* Overwrite the variable with the new value */
            newenv = malloc(_strlen(name) + _strlen(value) + 2);
            if (newenv == NULL) {
                errno = ENOMEM;
                return (-1);
            }
            _strcpy(newenv, name);
            _strcat(newenv, "=");
            _strcat(newenv, value);
            *envp = newenv;
            return (0);
        }

        envp++;
    }

    /* No existing variable with the given name has been found, so add a new one */
    newenv = malloc(_strlen(name) + _strlen(value) + 2);
    if (newenv == NULL) {
        errno = ENOMEM;
        return (-1);
    }
    _strcpy(newenv, name);
    _strcat(newenv, "=");
    _strcat(newenv, value);

    /* Expand the environment block by one and add the new variable */
    newenvp = realloc(environ, (environ_size + 2) * sizeof(char *));
    if (newenvp == NULL) {
        free(newenv);
        errno = ENOMEM;
        return (-1);
    }
    environ = newenvp;
    environ[environ_size++] = newenv;
    environ[environ_size] = NULL;

    return (0);
}

