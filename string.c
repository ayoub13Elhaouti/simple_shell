#include "shell.h"
/**
 * my_strcmp - campare two strings
 * @str1: 1st string
 * @str2: 2nd string
 *
 * Return: the difference between strs
 */
int	my_strcmp(char	*str1, char	*str2)
{
	int	i = 0;
	int	diff;

	while (*(str1 + i) == *(str2 + i) && *(str1 + i) != '\0')
		i++;
	diff = (*(str1 + i) - *(str2 + i));

	return (diff);
}

/**
 * my_strncmp - compare n elements of two strings.
 * @str1: 1st string.
 * @str2: 2nd string.
 * @nbr: nbr bytes.
 *
 * Return: the difference of str1 and str2.
 */
int	my_strncmp(char	*str1, char	*str2, int	nbr)
{
	int	i = 0;

	while (str1[i] && str2[i] && i < nbr)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

/**
 * my_strdup - duplicate a string
 * @str: the original string
 *
 * Return: duplicated string Pointer
 */
char	*my_strdup(char	*str)
{
	char	*p;
	int	i;
	int	ln;

	if (str == NULL)
		return (NULL);
	ln = my_strlen(str);
	p = malloc(sizeof(char) * (ln + 1));
	if (!p)
		return (NULL);
	for (i = 0; *str != '\0'; str++, i++)
		p[i] = str[0];
	p[i++] = '\0';
	return (p);
}

/**
 * my_strlen - calculate length of string
 * @str: the string
 *
 * Return: length of str
 */
int	my_strlen(char	*str)
{
	int	i = 0;

	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

/**
 * my_strchr - locate a character in a string
 * @str: the string to search in
 * @c: the character to to locate
 *
 * Return: pointer to the 1st occurrence of c, NULL ealse
 */
char	*my_strchr(char	*str, char	c)
{
	while (*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	if (!c)
		return (str);
	return (NULL);
}
