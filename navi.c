/*
** EPITECH PROJECT, 2018
** navi
** File description:
** by Oriol
*/

#include "list.h"
#include "get_next_line.h"

void printbincharpad(char c)
{
	int	i;
	
	for (i = 7; i >= 0; --i) {
		putchar( (c & (1 << i)) ? '1' : '0' );
	}
	putchar('\n');
}

int	main(int ac, char **av)
{
	char	**user_map;
	char    **user_map_empty;

	if (ac != 2 && ac != 3)
		exit(84);
	printbincharpad(10);
	my_putstr("my_pid ");
	my_put_nbr((int)getpid());
	my_putstr("\n");
	if (ac == 2) {
		my_putstr("waiting for enemy conection...");
		user_map = open_function(av[1]);
	}
	if (ac == 3)
		user_map = open_function(av[2]);
	user_map_empty = feed_empty(user_map);
	who_sig_me(user_map, user_map_empty, ac, av[1]);
	return (0);
}
	
