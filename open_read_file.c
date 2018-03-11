/*
** EPITECH PROJECT, 2018
** navi
** File description:
** by oriol
*/

#include "list.h"
#include "get_next_line.h"

char	**feed_empty(char **av)
{
	char	**str;
	int	i = 0;
	int	g = 0;

	str = malloca(11, 8);
	for (g = 0; av[g] != NULL; g++) {
		for (i = 0; av[g][i] != '\0'; i++) {
			str[g][i] = av[g][i];
			if (av[g][i] > '1' && av[g][i] < '6' && i != 0)
				str[g][i] = '.';
		}
		str[g][i] = av[g][i];
	}
	str[g][0] = '\0';
	str[g] = NULL;
	return (str);
}

char    **opene(char *av)
{
	int     fd;
	char    buf[2];
	char    **ptr;
	int     i;
	int     num[2];

	num[0] = 0;
	num[1] = 0;
	fd = open(av, O_RDONLY);
	for (i = read(fd, buf, 1);
	     i != 0; i = read(fd, buf, 1)) {
		if (buf[0] == '\n')
			num[0]++;
		num[1]++;
	}
	ptr = malloca(8, 8);
	return (ptr);
}

char    **insert_map(char *av, char **ptr)
{
 	int     fd;
	char    buf[2];
	int     i;
	int     num[2] = {0, 0};

	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (NULL);
	for (i = read(fd, buf, 1);
	     i != 0; i = read(fd, buf, 1)) {
		ptr[num[0]][num[1]] = buf[0];
		if (buf[0] == '\n') {
			ptr[num[0]][num[1] + 1] = '\0';
			num[0]++;
			num[1] = -1;
		}
		num[1]++;
	}
	ptr[num[0]] = NULL;
        return (ptr);
}

char	**create_map(char **map)
{
	char	**final_map;
	int	x1 = 0;
	int	y1 = 0;
	int	x2 = 0;
	int	y2 = 0;
	int	i;
	int	y;
	int	num;
	int	x;

	if (check_map(map) == 1) {
		return (NULL);
	}
	my_putstr("test");
	final_map = create_map_base();
	for (i = 0; map[i] != NULL; i++) {	
		x1 = (map[i][2] - 'A' + 1) * 2;
		y1  = map[i][3] - '0' + 1;
		x2 = (map[i][5] - 'A' + 1) * 2;
		y2 = map[i][6] - '0' + 1;
		num = map[i][0] - '0';
		x = 0;
		if (x1 == x2) {
			for (y = num; y > 0; y--)
				final_map[y1 + (y - 1)][x1] = num + '0';
		}
		else if (y1 == y2) {
			for (y = num; y > 0; y--) {
				final_map[y1][x2 - x] = num + '0';
				x = x + 2;
			}
		}
	}
	return (final_map);
}

char	**open_function(char *av)
{
	char	**user1_map;
	char	**final_map;

	user1_map = malloca(8, 8);
	user1_map = insert_map(av, user1_map);
	if (user1_map == NULL)
		return (NULL);
	final_map = create_map(user1_map);
	if (final_map == NULL)
		return (NULL);
	free(user1_map);
	return (final_map);
}
