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
	if ((fd = open(av, O_RDONLY)) == -1)
		exit(84);

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
	int     num[2] = {0,0};

	if ((fd = open(av, O_RDONLY)) == -1)
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
	for (i = 0; ptr[i] != NULL; i++)
		printf("ptr[i]:%s\n", ptr[i]);
	return (ptr);
}

char	**create_map(char map)
{
	char	**final_map;
	int	x = 0;
	int	y = 0;
	int	i;
	int	num;
	
	final_map = malloca(8, 8);
	final_map[0] = " |A B C D E F G H\n";
	final_map[1] = "-+-----------------";
	for (i = 2; i != 9; i++)
		final_map[i] = "1|. . . . . . . .\n";
	final_map[i] == NULL;
	for (i = 0; final_map[i] != NULL; i++) {
		x = (map[2] - 'A' + 1) * 2;
		y  = map[3] - 'O' + 1;
		for (num = map[0] - 'O';
		
		final_map[y][x]
		printf("final:%s\n", final_map[i]);
}

char	**open_function(char	*av)
{
	char	**user1_map;
	char	**final_map;
	
	//user1_map = opene(av);
	user1_map = malloca(8, 8);
	user1_map = insert_map(av, user1_map);
	final_map = create_map(user1_map);
	free(user1_map);
	return (user1_map);
}
