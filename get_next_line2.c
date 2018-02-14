/*
** EPITECH PROJECT, 2018
** 
** File description:
**
*/

#include "get_next_line.h"
#include "list.h"

int	sum_count(int *count, int size)
{
	if (size == - 1)
		return (1);
	(*count) = (*count) + BUFF;
	return (0);
}

char    *put_in_str(char *ptr, char **buffer, int i)
{
	int     count;

	for (count = 0; count < BUFF; count++) {
		ptr[i] = (*buffer)[count];
		i++;
		if ((*buffer)[count + 1] == 3 || (*buffer)[count] == 3)
			(*buffer) = NULL;
		if ((*buffer)[count] == '\n')
			return (ptr);
	}
	return (ptr);
}

char	*feed_after_n(char *buffer)
{
	if(buffer == NULL)
		buffer = malloc(sizeof(char) * BUFF);
	else
		buffer = save_after_n(buffer);
	return (buffer);
}

char	*inside_loop(char *str, int count, char **buffer, int *i)
{
	str = reallocate(str, count);
	str = put_in_str(str, &(*buffer), count);
	(*i) = is_line(str, count + BUFF);
	return (str);
}

char	*buffer_transform(char *buffer, int *a, int *i)
{
	while ((*i) + 1 < BUFF) {
		buffer[(*a)] = buffer[(*i) + 1];
		(*a)++;
		(*i)++;
	}
	return (buffer);
}
