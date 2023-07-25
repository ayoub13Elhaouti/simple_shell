#include "shell.h"

/**
 * path_finder - find the path of cmd
 * using the env variable
 *
 * Return: the path pointer, NULL else.
 */

char	*path_finder(void)
{
	int	element_nbr;
	char	**env = environ;
	char	*path_name = NULL;

	while (*env)
	{
		if (my_strncmp(*env, "PATH=", 5) == 0)
		{
			path_name = *env;
			while (*path_name && element_nbr < 5)
			{
				path_name++;
				element_nbr++;
			}
			return (path_name);
		}
		env++;
	}
	return (NULL);
}

/**
 * path_combiner - combine the command
 * with its path
 *
 * @cmd: the command
 * @path: the path to add.
 * Return: string of combined command and path.
 */

char	*path_combiner(char	*path, char	*cmd)
{
	size_t	i = 0;
	size_t	j = 0;
	char	*buffer;

	if (cmd == 0)
		cmd = "";
	if (path == 0)
		path = "";
	buffer = malloc(sizeof(char) * (my_strlen(path) + my_strlen(cmd) + 2));
	if (!buffer)
		return (NULL);
	while (path[i] != '\0')
	{
		buffer[i] = path[i];
		i++;
	}
	if (path[i - 1] != '/')
	{
		buffer[i] = '/';
		i++;
	}
	while (cmd[j] != '\0')
	{
		buffer[i + j] = cmd[j];
		j++;
	}
	buffer[i + j] = '\0';
	return (buffer);
}

/**
 * path_checker - see if the path exists or not.
 *
 * @path:the path from stdin.
 * @cmd: the command.
 *
 * Return: the combined command and path if
 * it's valid, NULL for else.
 */

char	*path_checker(char	**path, char	*cmd)
{
	int	i;
	char	*complete;

	i = 0;
	while (path[i])
	{
		complete = path_combiner(path[i], cmd);
		if (access(complete, F_OK | X_OK) == 0)
			return (complete);
		free(complete);
		i++;
	}
	return (NULL);
}
