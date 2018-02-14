/*
** EPITECH PROJECT, 2017
**
** File description:
**
*/

#ifndef LIST_H_
#define LIST_H_

#define BUFF	10

int	sum_count(int *count, int size);
char	*buffer_transform(char *buffer, int *a, int *i);
char	*reallocate(char *str, int count);
char	*save_after_n(char *buffer);
char	*inside_loop(char *str, int count, char **buffer, int *i);
char	*feed_after_n(char *buffer);
char	*put_in_str(char *ptr, char **buffer, int i);
int	get_the_line(int count, int *line, int lines, char **map);
void	error(int ac);
char	*feed_buffer(int fd, char *buffer);
char	*save_after_n(char *buffer);
char	*main_loop(int fd, int count,char *str,char **buffer);
char	*put_in_str(char *ptr, char **buffer, int i);
int	is_line(char *str, int n);
int	opening(char *av);

#endif
