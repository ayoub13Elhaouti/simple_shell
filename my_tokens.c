#include "shell.h"

/**
 * my_tokens - take data from stdin
 * and turn it into tokens.
 * @input: strings to be toknized.
 *
 * Return: pointer to the array of strings.
 */

char	**my_tokens(char	*input)
{
	char	*white_del = " :\t\r\n", *buffer = NULL, *tk = NULL, *pth_buffer = NULL;

	int	ln_token;
	char	**tk_list = NULL;
	size_t	i = 0, value = 0;

	buffer = my_strdup(input);
	if (!buffer)
		return (NULL);
	pth_buffer = buffer;
	while (*pth_buffer)
	{
		if (my_strchr(white_del, *pth_buffer) != NULL && value == 0)
		{
			ln_token++;
			value = 1;
		}
		else if (my_strchr(white_del, *pth_buffer) == NULL && value == 1)
			value = 0;
		pth_buffer++;
	}
	tk_list = malloc(sizeof(char	*) * (ln_token + 1));
	tk = strtok(buffer, white_del);
	while (tk)
	{
		tk_list[i] = my_strdup(tk);
		if (tk_list[i] == NULL)
		{
			free(tk_list);
			return (NULL);
		}
		tk = strtok(NULL, white_del);
		i++;
	}
	tk_list[i] = '\0';
	free(buffer);
	return (tk_list);
}
