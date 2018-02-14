/*
** EPITECH PROJECT, 2018
** navi
** File description:
** by Oriol
*/

#include "list.h"
#include "get_next_line.h"

int	print_map(char **user1, char **user2)
{
	int	i;

	my_putstr("my positions:\n");
	for (i = 0; user1 != NULL; i++)
		printf("user:%s",user1[i]);
		//my_putstr(user1[i]);
	/*my_putstr("enemy's position:\n");
	for (i = 0; user1 != NULL; i++)
		my_putstr(user2[i]);
		my_putstr("\n");*/
	return (0);
}
