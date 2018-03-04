/*
** EPITECH PROJECT, 2018
** puts
** File description:
** puts
*/
#include "list.h"

void	my_putchar_error(char c)
{
	write(1, &c, 1);
}

int	my_putstr_error(char *str)
{
	int     i = 0;

	while(str[i] != '\0') {
		my_putchar_error(str[i]);
		i++;
	}
	return (0);
}
