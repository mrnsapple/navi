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
	
	str = malloca(8, 8);
	for (g = 0; av[g] != NULL; g++) {
		for (i = 0; av[g][i] != '\0'; i++) {
			str[g][i] = av[g][i];
			if (av[g][i] > '1' && av[g][i] < '6' && i != 0)
				str[g][i] = '.';
		}
		str[g][i] = '\0';
	}
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
        ptr = malloca(num[0], num[1] / num [0]);
        return (ptr);
}

char    **insert_map(char *av, char **ptr)
{
 	int     fd;
        char    buf[2];
        int     i;
	int     num[2] = {0,0};

        if ((fd = open(av, O_RDONLY)) == -1)
                exit(84);
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

char	**open_function(char	*av)
{
	char	**user1_map;
	
	user1_map = opene(av);
	user1_map = insert_map(av, user1_map);
	return (user1_map);
}
