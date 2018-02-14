/*
** EPITECH PROJECT, 2018
** navi
** File description:
** by Oriol
*/

#include "list.h"
#include "get_next_line.h"

int	hit(char *a, int pid)
{
	int	x = 0;
	int	y = 0;
	
	if (a == NULL)
		return (0);
	if (a[0] >= 'A' && a[0] <= 'H' && a[1] >= '1' && a[1] <= '9' &&
	    a[2] == '\0') {
		x = (a[0] - 'A' + 1) * 2;
		y = a[1] - '0' + 1;
	}
	printf("x:%d, y:%d\n",x, y);
	for (x = x; x != 0; x--)
		kill(pid, SIGUSR1);
	for (y = y; y != 0; y--)
		kill(pid, SIGUSR2);
	
	return (0);
}

int	print_map(char **user1, char **user2, int ac)
{
	int	i = 0;

	if (ac == 3)
		my_putstr("succesfully connected\n\n");
	my_putstr("my positions:\n");
	for (i = 0; user1[i] != NULL; i++)
		my_putstr(user1[i]);
	my_putstr("\nenemy's position:\n");
	for (i = 0; user2[i] !=  NULL; i++)
		my_putstr(user2[i]);
	my_putstr("\n");
	if (ac == 3)
		my_putstr("waiting for enemy's atack...\n");
	if (ac == 2)
		my_putstr("atack :");	
	return (0);
}
