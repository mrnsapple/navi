/*
** EPITECH PROJECT, 2018
** 
** File description:
**
*/

#include "get_next_line.h"
#include "list.h"

char	*save_after_n(char *buffer)
{
	int	i;
	int	g = 0;
	int	a = 0;

	for (i = 0; i < BUFF; i++) {
		if (buffer[i] == '\n')
			g = 1;
		if (g == 1 && i + 1 < BUFF) {
			buffer = buffer_transform(buffer, &a, &i);
			buffer[a] = '\0';
			return (buffer);
		}
	}
	buffer[i] = '\0';
	return (buffer);
}

int	is_line(char *str, int n)
{
	int	i;

	for (i = 0; i < n; i++) {
		if (str[i] == '\n')
			return (i);
	}
	return (0);
}

char	*reallocate(char *str, int count)
{
	char	*ptr;
	int	i;

	ptr = malloc(sizeof(char) * count + BUFF * 2);
	for (i = 0; i <= count; i++)
		ptr[i] = str[i];
	free(str);
	return (ptr);
}

char	*main_loop(int fd, int count,char *str,char **buffer)
{
 	int	size;
	int	i = 0;

	size = read(fd, (*buffer), BUFF);
	if ((*buffer)[0] == '\n')
		return ((*buffer));
	if (size < 1)
		return (NULL);
	while (size > 0 && i == 0) {
		str = inside_loop(str, count, &(*buffer), &i);
		if (i == 0)
			size = read(fd, (*buffer), BUFF);
		if (sum_count(&count, size) == 1)
			return (NULL);
	}
	if (size <= 0)
		(*buffer) = NULL;
	str[i] = '\0';
	(*buffer)[BUFF] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	char		*str;
	int		count = 0;
	static char	*buffer = NULL;

	str = malloc(sizeof(char) * 200);
	buffer = feed_after_n(buffer);
	for (count = 0; buffer[count] != '\0' &&
		     BUFF != 1 && buffer != NULL; count++) {
		str[count] = buffer[count];
		if(str[count] == '\n') {
			str[count] = '\0';
			return (str);
		}
	}
	str[count] = '\0';
	buffer = malloc(sizeof(char) * BUFF);
	str = main_loop(fd, count, str, &buffer);
	return (str);
}
