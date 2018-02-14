/*
** EPITECH PROJECT, 2018
** navi
** File description:
** by Oriol
*/

#include "list.h"
#include "get_next_line.h"

int	main(int ac, char **av)
{
	char	**user1_map;
	char	**user2_map;
	char	**user_map_empty;
	int	i;

	
	if (ac == 2) {
		user1_map = open_function(av[1]);
		for (i = 0; user1_map[i] != NULL; i++)
			printf("%s",user1_map[i]);
		user_map_empty = feed_empty(user1_map);
		for (i = 0; user_map_empty[i] != NULL; i++)
			printf("map:%s",user_map_empty[i]);
	}
	if (ac == 3) {
		user2_map = open_function(av[2]);
	}
	my_putstr("my_pid ");
	my_put_nbr((int)getpid());
	my_putstr("\n");
	who_sig_me();
	return (0);
}
	
