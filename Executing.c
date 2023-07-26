#include "shell.h"

/**
 * buffer_cleaner - free all the buffers
 * @list: buffers to empty
 *
 * return: void
 */

void	buffer_cleaner(char	**list)
{
	int	count = 0;

	if (list == NULL)
		return;
	while (list[count])
	{
		free(list[count]);
		count++;
	}
}

/**
 * executin_func - execute the commmand from the shell prompt
 * @command: the entered command
 * @ar_cmd: array of command and their arguments
 *
 * Return: void
 */

void	executin_func(char	*command, char	**ar_cmd)
{
	int	stat;
	pid_t	child;
	char	**env = environ;

	child = fork();
	if (child < 0)
		perror(command);
	else if (child == 0)
	{
		execve(command, ar_cmd, env);
		buffer_cleaner(ar_cmd);
		exit(98);
	}
	else
		wait(&stat);
}
