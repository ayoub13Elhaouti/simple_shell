#include "shell.h"

/**
 * my_putstr - print a string
 * @str: the string to print
 *
 * Return: void.
 */

void	my_putstr(char	*str)
{
	int	i = 0;

	while (str[i])
	{
		my_putchar(str[i]);
		i++;
	}
}
