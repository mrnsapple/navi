/*
** EPITECH PROJECT, 2018
** navi
** File description:
** by Oriol
*/

#include "list.h"
#include "get_next_line.h"

void user_help(char *av)
{
	if (av[0] == '-' && av[1] == 'h' && av[2] == '\0') {
		my_putstr("USAGE\n\t./navi [first_player_pid] navi_posi");
		my_putstr("tions\nDESCRIPTION\n\tfirst_player_pid:   ");
		my_putstr("only for the 2nd player.  pid of the first pla");
		my_putstr("yer.\n\tnavy_positions:   file representing the");
		my_putstr(" positions of the ships\n");
	}
}

int	main(int ac, char **av)
{
	char	**user_map;
	char    **user_map_empty;

	if (ac == 2)
		user_help(av[1]);
	if (ac != 2 && ac != 3)
		exit(84);
	my_putstr("my_pid: ");
	my_put_nbr((int)getpid());
	my_putstr("\n");
	if (ac == 2)
		user_map = open_function(av[1]);
	if (ac == 3) {
		my_putstr("succesfully connected\n\n");
		user_map = open_function(av[2]);
	}
	user_map_empty = feed_empty(user_map);
	if (ac == 3)
		who_sig_me(user_map, user_map_empty, ac, my_get_nbr(av[1]));
	if (ac == 2) {
		my_putstr("waiting for enemy conection...\n");
		who_sig_me(user_map, user_map_empty, ac, getpid());
	}
	return (0);
}
	
