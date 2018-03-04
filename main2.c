/*
** EPITECH PROJECT, 2018
** navi
** File description:
** main2
*/
#include "list.h"

int     is_there_ship(struct coord_t num, char **user1_map, char **user2_map, int ac)
{
	char    a[4];

	if (ac <= 3)
		return (3);
	if (num.x != 0 && num.y != 0) {
		a[0] = (num.x / 2) - 1 + 'A';
		a[1] = num.y - 1 + '0';
		a[2] = '\0';
		my_putstr(a);
		if (user1_map[num.y][num.x] != '.') {
			my_putstr("   hit\n\n");
			user1_map[num.y][num.x] = 'x';
			return (0);
		} else {
			my_putstr("   missed\n\n");
			user1_map[num.y][num.x] = 'o';
			return (1);
		}
	}
	if (user1_map[num.y][num.x] != '.')
		return (0);
	return (1);
}

char    **is_there_ship_atack(struct coord_t num,
			      char **user1_map, char **user2_map, char *a)
{
	int     x;
	int     y;

	if (num.x == 3 && num.y == 0) {
		x = ((a[0] - 'A' + 1) * 2);
		y = a[1] - '0' + 1;
		my_putstr(a);
		my_putstr(":  hit\n");
		user2_map[y][x] = 'x';
	}
	if (num.x == 2 && num.y == 0) {
		x = ((a[0] - 'A' + 1) * 2);
		y = a[1] - '0' + 1;
		my_putstr(a);
		my_putstr(":  missed\n");
		user2_map[y][x] = 'o';
	}
	return (NULL);
}

int     lose(char **map)
{
	int     i;
	int     g;

	for (i = 2; map[i] != NULL; i++) {
		for (g = 2; map[i][g] != '\0'; g++) {
			if (map[i][g] == '2' || map[i][g] == '3'
			    || map[i][g] == '4' || map[i][g] == '5')
				return (1);
		}
	}
	my_putstr("\nEnemy won\n");
	return (0);
}

int     you_won(struct coord_t num)
{
	if (num.x == 4 && num.y == 0) {
		my_putstr("You win\n");
		return (0);
	}
	return (1);
}

int     wait_1_signal(int ac, int num_print)
{
	if (ac == 2) {
		for (num_print = pause();
		     num_print != -1; num_print = pause());
		my_putstr("\nenemy connected\n\n");
	}
	num_print = ac;
	return (num_print);
}
