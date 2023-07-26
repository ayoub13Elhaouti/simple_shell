#include "shell.h"

/**
 * sig_tracker - tracking the interactive mode
 * @value: sig value
 *
 * Return: void
 */

void	sig_tracker(int	value)
{
	(void)value;
	write(2, "\n", 1);
	write(2, "> ", 2);
}

/**
 * prompt - waiting for the user to write
 * their command.
 * Return: void.
 */

void	prompt(void)
{
	struct flags flags;

	if ((isatty(0) == 1) && (isatty(1) == 1))
		flags.interactive = 1;
	if (flags.interactive)
		write(2, "> ", 2);
}

/**
 * main - the program that combines
 * all propreties, functions and builtins
 * to have an interactive shell
 * @argc: the arguments count.
 * @argv: arguments array.
 * @envp: environment array.
 *
 * Return: the state of program.
 *
 */

int	main(int	argc, char	**argv, char	*envp[])
{
	struct	info info;
	struct	flags flags = {true};
	char	**pth_list = NULL, **cmd = NULL;
	char	*pth = NULL, *pth_cmd = NULL, *ln = NULL;
	size_t	buffer_size = 0;
	ssize_t	line_size;
	(void)envp, (void)argv;

	if (argc < 1)
		return (-1);
	signal(SIGINT, sig_tracker);
	while (1)
	{
		/* buffer_cleaner(cmd); */
		/* buffer_cleaner(pth_list); */
		/* free(pth_cmd); */
		prompt();
		line_size = getline(&ln, &buffer_size, stdin);
		if (line_size < 0)
			break;
		info.ln_count++;
		if (ln[line_size - 1] == '\n')
			ln[line_size - 1] = '\0';
		cmd = my_tokens(ln);
		if (cmd == NULL || *cmd == NULL || **cmd == '\0')
			continue;
		if (cmd_checker(cmd, ln))
			continue;
		pth = path_finder();
		pth_list = my_tokens(pth);
		pth_cmd = path_checker(pth_list, cmd[0]);
		if (!pth_cmd)
			perror(argv[0]);
		else
			executin_func(pth_cmd, cmd);
	}
	if (line_size < 0 && flags.interactive)
		write(STDERR_FILENO, "\n", 1);
	free(ln);
	return (0);
}
