#include "shell.h"

/**
 * _is_getline - function that stores the user's input command into a buffer
 *
 * @str: buffer
 *
 * Return: number of character read
 */

size_t _is_getline(char **str)
{
	ssize_t i = 0, size = 0, t = 0, t2 = 0, n = 0;
	char buff[1024];

	while (t2 == 0 && (i = read(STDIN_FILENO, buff, 1024 - 1)))
	{
		if (i == -1)
			return (-1);

		buff[i] = '\0';

		n = 0;
		while (buff[n] != '\0')
		{
			if (buff[n] == '\n')
				t2 = 1;
			n++;
		}

		if (t == 0)
		{
			i++;
			*str = malloc(sizeof(char) * i);
			*str = _isstrcpy(*str, buff);
			size = i;
			t = 1;
		}
		else
		{
			size += i;
			*str = _isstrcat(*str, buff);
		}
	}
	return (size);
}
