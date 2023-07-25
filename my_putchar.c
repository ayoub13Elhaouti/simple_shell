#include "shell.h"

/**
 * my_putchar - print a character
 * @x: the character
 *
 * Return: 1 on success, and -1 else.
 */
int	my_putchar(char	x)
{
	return (write(1, &x, 1));
}
