#include "headers.h"
char *get_location(char *command);
char *path_dir(char *path);
list_t *get_dir_path(char *path);

/**
 * get_location - finds a command in the PATH.
 * @command: The command to find.
 *
 * Return: If error occurs or command can't be found - NULL.
 *         else full pathname of command.
 */
char *get_location(char *command)
{
	char **path, *tmp;
	list_t *dirs, *head;
	struct stat st;

	path = _getenv("PATH");
	if (!path || !(*path))
		return (NULL);

	dirs = get_path_dir(*path + 5);
	head = dirs;

	while (dirs)
	{
		tmp = malloc(_strlen(dirs->dir) + _strlen(command) + 2);
		if (!tmp)
			return (NULL);

		_strcpy(tmp, dirs->dir);
		_strcat(tmp, "/");
		_strcat(tmp, command);

		if (stat(tmp, &st) == 0)
		{
			free_list(head);
			return (tmp);
		}

		dirs = dirs->next;
		free(tmp);
	}

	free_list(head);

	return (NULL);
}

/**
 * path_dir - Copies path and replaces leading/sandwiched/trailing
 *		   colons (:) with current working directory.
 * @path: colon-separated list of dirs.
 *
 * Return: copy of path with leading/sandwiched/trailing colons replaced
 *	   with the cwd.
 */
char *path_dir(char *path)
{
	int i, len = 0;
	char *path_cpy, *pwd;

	pwd = *(_getenv("PWD")) + 4;
	for (i = 0; path[i]; i++)
	{
		if (path[i] == ':')
		{
			if (path[i + 1] == ':' || i == 0 || path[i + 1] == '\0')
				len += _strlen(pwd) + 1;
			else
				len++;
		}
		else
			len++;
	}
	path_cpy = malloc(sizeof(char) * (len + 1));
	if (!path_cpy)
		return (NULL);
	path_cpy[0] = '\0';
	for (i = 0; path[i]; i++)
	{
		if (path[i] == ':')
		{
			if (i == 0)
			{
				_strcat(path_cpy, pwd);
				_strcat(path_cpy, ":");
			}
			else if (path[i + 1] == ':' || path[i + 1] == '\0')
			{
				_strcat(path_cpy, ":");
				_strcat(path_cpy, pwd);
			}
			else
				_strcat(path_cpy, ":");
		}
		else
			_strncat(path_cpy, &path[i], 1);

	}
	return (path_cpy);
}

/**
 * get_dir_path - tokenizes a colon-separated list of
 *                dirs into a list_s linked list.
 * @path: colon-separated list of dirs.
 *
 * Return: pointer to linked list.
 */
list_t *get_dir_path(char *path)
{
	int i;
	char **dirs, *path_cpy;
	list_t *head = NULL;

	path_cpy = path_dir(path);
	if (!path_cpy)
		return (NULL);
	dirs = _strtok(path_cpy, ":");
	free(path_cpy);
	if (!dirs)
		return (NULL);

	for (i = 0; dirs[i]; i++)
	{
		if (add_node_end(&head, dirs[i]) == NULL)
		{
			free_list(head);
			free(dirs);
			return (NULL);
		}
	}

	free(dirs);

	return (head);
}
