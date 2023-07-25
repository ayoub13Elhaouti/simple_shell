#ifndef	SHELL_H
#define	SHELL_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <time.h>
#include <sys/types.h>
#include <stdbool.h>

/* environment variables */
extern char **environ;
extern __sighandler_t signal(int __sig, __sighandler_t __handler);

/* path functions */
char	*path_finder(void);
char	*path_combiner(char	*path, char	*cmd);
char	*path_checker(char	**path, char	*cmd);

/* strings functions*/
void	executin_func(char	*command, char	**ar_cmd);
int	my_strcmp(char *str1, char *str2);
int	my_strlen(char *str);
int	my_strncmp(char *str1, char *str2, int n);
char	*my_strdup(char *str);
char	*my_strchr(char *str, char c);
void	my_putstr(char	*str);
int	my_putchar(char	x);

/* builtin functions and commands */
void	built_exit(char	**cmd, char	*input);
void	built_env(void);
int	built_incmp(char	**command, char	*buffer);
int	cmd_checker(char	**command, char	*buffer);

/* updated free function */
void	buffer_cleaner(char	**list);

/* shell.c functions */
void	sig_tracker(int	value);
void	prompt(void);
char	**my_tokens(char	*str);

struct	builtin
{
	char *env;
	char *exit;
};

struct	info
{
	int	final_exit;
	int	ln_count;
};

struct	flags
{
	bool	interactive;
};

#endif /* SHELL_H */
