#include "shell.h"

/**
 * built_exit - built exit command
 * @cmd: tokenized command from terminal
 * @input: the line from stdin
 *
 * Return: void
 */

void	built_exit(char	**cmd, char	*input)
{
	free(input);
	buffer_cleaner(cmd);
	exit(0);
}

/**
 * built_env - built env command
 *
 * Return: void
 */

void	built_env(void)
{
	int	i;
	char	**env = environ;

	i = 0;
	while (env[i])
	{
		write(1, (const void	*)env[i], my_strlen(env[i]));
		write(1, "\n", 1);
		i++;
	}
}

/**
 * built_incmp - execute builtin commands
 * @command: env or exit
 * @buffer: content of stdin
 *
 * Return: 1 if the command is executed, 0 else
 */
int	built_incmp(char	**command, char	*buffer)
{
	struct	builtin	builtin = {"env", "exit"};

	if (my_strcmp(*command, builtin.env) == 0)
	{
		built_env();
		return (1);
	}
	else if (my_strcmp(*command, builtin.exit) == 0)
	{
		built_exit(command, buffer);
		return (1);
	}
	return (0);
}

/**
 * cmd_checker - checking if command is a builtin
 * @command: the command to check
 * @buffer: line in the stdin
 *
 * Return: 0 if the command is not executed, 1 else
 */

int	cmd_checker(char	**command, char	*buffer)
{
	if (built_incmp(command, buffer))
		return (1);
	else if (**command == '/')
	{
		executin_func(command[0], command);
		return (1);
	}
	return (0);
}
