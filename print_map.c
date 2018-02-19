/*
** EPITECH PROJECT, 2018
** navi
** File description:
** by Oriol
*/

#include "list.h"
#include "get_next_line.h"


int	hit_return(int ret, int pid)
{
	if (ret == 0) {
		kill(pid, SIGUSR1);
		usleep(1);
		kill(pid, SIGUSR1);
		usleep(1);
		kill(pid, SIGUSR1);
		usleep(1);
		kill(pid, SIGUSR2);
		usleep(1);
	}
	if (ret == 1) {
		kill(pid, SIGUSR1);
		usleep(1);
		kill(pid, SIGUSR1);
		usleep(1);
		kill(pid, SIGUSR2);
		usleep(1);
	}
	return (0);
}

int	send_lose(int pid)
{
	kill(pid, SIGUSR1);
	usleep(1);
	kill(pid, SIGUSR1);
	usleep(1);
	kill(pid, SIGUSR1);
	usleep(1);
	kill(pid, SIGUSR1);
	usleep(1);
	kill(pid, SIGUSR2);
	usleep(1);
	return (0);
}

int	hit(char *a, int pid)
{
	int	x = 0;
	int	y = 0;

	if (a == NULL)
		return (0);
	if (a[0] >= 'A' && a[0] <= 'H' && a[1] >= '1' && a[1] <= '9' &&
	    a[2] == '\0') {
		x = ((a[0] - 'A' + 1) * 2);
		//y = a[1] - '0' + 1;
		y = a[1] - '0' + 1;
	}
	//y++;
	//printf("x:%d, y:%d\n",x, y);
	for (; y != 0; y--) {
		//printf("!num2\n");
		kill(pid, SIGUSR2);
		usleep(1);
	}
	for (; x != 0; x--) {
		//printf("num\n");
		kill(pid, SIGUSR1);
		usleep(1);
	}
	kill(pid, SIGUSR2);
	usleep(1);
	return (0);
}

char	*atack(char *a)
{
	int		i = 0;
	//int		g;
	
	while (i == 0) {
		my_putstr("atack:  ");
		counter(0, 0, 0);
		for (a = get_next_line(0); a == NULL; a = get_next_line(0)); 
		if (a[0] >= 'A' && a[0] <= 'H' && a[1] >= '1' && a[1] <= '9' &&
		    a[2] == '\0')
			i = 1;
		else
			my_putstr("wrong position\n");
	}
	return (a);
}

void	print_map_board(char **user1, char **user2)
{
	int	i;

	my_putstr("my positions:\n");
	for (i = 0; user1[i] != NULL; i++)
		my_putstr(user1[i]);
	my_putstr("enemy's position:\n");
	for (i = 0; user2[i] !=  NULL; i++)
		my_putstr(user2[i]);
	}

struct coord_t	print_map(char **user1, char **user2, int ac, int *num)
{
	int	i = 0;
	struct coord_t	value = {.x = 0, .y = 0};

	//printf("num:%d\n", (*num));
	if ((*num) >= 3) {
		counter(0, 0, 0);
		if ((*num) == 3 && ac == 3)
			print_map_board(user1, user2);
		my_putstr("\nwaiting for enemy's atack...\n");
		for (i = pause(); i != -1; i = pause());
		//for (i = pause(); i != -1; i = pause());
		for (value = counter(0, 0 , 1); value.z != 3;
		     value = counter(0, 0, 1));
        }
	//print_map_board(user1, user2);
	//value.y--;
	(*num)++;
	return (value);
}
