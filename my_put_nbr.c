/*
** EPITECH PROJECT, 2018
**
** File description:
**
*/

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "list.h"

int	my_put_nbr(int nb)
{
	int     i;

	if(nb < 0) {
	 	my_putchar('-');
		nb = nb * (- 1);
	}
	if(nb >= 0) {
		if(nb >= 10) {
			i = nb % 10;
			nb = (nb - i) / 10;
			my_put_nbr(nb);
			my_putchar('0' + i);
		}
		else
			my_putchar('0' + nb % 10);
	}
	return (0);
}

