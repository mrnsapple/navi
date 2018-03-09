/*
** EPITECH PROJECT, 2018
** Navy
** File description:
** Create map
*/
#include "list.h"

char    **create_map_base(void)
{
	char    **map;
	int     i;
	int     y;

	map = malloca(8, 8);
	map[0] = " |A B C D E F G H\n";
	map[1] = "-+---------------\n";
	for (i = 2; i != 10; i++) {
		map[i][0] = (i - 1) + '0';
		map[i][1] = '|';
		for (y = 2; y < 15; y+=2){
			map[i][y] = '.';
			map[i][y + 1] = ' ';
		}
		map[i][y] = '.';
		map[i][y + 1] = '\n';
	}
	return (map);
}

int	check_map(char **map)
{
	int	x1 = 0;
	int	x2 = 0;
	int	y1 = 0;
	int	y2 = 0;
	int	i;
	int	num = 0;
	int	nb;
	
	for (i = 0; map[i] != NULL; i++) {
		x1 = (map[i][2] - 'A' + 1) * 2;
		y1  = map[i][3] - '0' + 1;
		x2 = (map[i][5] - 'A' + 1) * 2;
		y2 = map[i][6] - '0' + 1;
		num = map[i][0] - '0';
		if (x1 == x2) {
			nb = y2 + 1 - y1;
			if (num != nb)
				return (1);
		}
		else if (y1 == y2) {
			nb = (x2 / 2) + 1 - (x1 / 2);
			if (num != nb)
				return (1);
		}
	}
	return (0);
}
