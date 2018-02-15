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
	char	**user_map;
	char    **user_map_empty;

	if (ac != 2 && ac != 3)
		exit(84);
	my_putstr("my_pid: ");
	my_put_nbr((int)getpid());
	my_putstr("\n");
	if (ac == 2)
		user_map = open_function(av[1]);
	if (ac == 3)
		user_map = open_function(av[2]);
	user_map_empty = feed_empty(user_map);
	if (ac == 3)
		who_sig_me(user_map, user_map_empty, ac, my_get_nbr(av[1]));
	if (ac == 2)
		who_sig_me(user_map, user_map_empty, ac, getpid());
	return (0);
}
	
