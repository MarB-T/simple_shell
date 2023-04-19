#include "headers.h"

/**
 * get_location - returns the path of a command
 * @cmd: pointer to path
 *
 * Return: path of command
 */

char *get_location(char *cmd)
{
	char *path, *path_cpy, *token, *file_path;
	int cmd_len, dir_len;
	struct stat buff;

	path = getenv("PATH");
	if (path)
	{
		path_cpy = strdup(path);
		cmd_len = strlen(cmd);
		token = strtok(path_cpy, ":");
		while (token)
		{
			dir_len = strlen(token);
			file_path = malloc(cmd_len + dir_len + 2);

			strcpy(file_path, token);
			strcat(file_path, "/");
			strcat(file_path, cmd);
			strcat(file_path, "\0");
			if (stat(file_path, &buff) == 0)
			{
				free(path_cpy);
				return (file_path);
			}
			else
			{
				free(file_path);
				token = strtok(NULL, ":");
			}
		}
		free(path_cpy);
		if (stat(cmd, &buff) == 0)
		{
			return (cmd);
		}
		return (NULL);
	}
	return (NULL);
}

