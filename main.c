/*
** EPITECH PROJECT, 2018
** bs_NAVI
** File description:
** by Oriol
*/

#include "list.h"

struct coord_t	counter(int x, int y)
{
	static struct coord_t	a = {.x = 0, .y = 0}; 
	
	
	//a->x = 0;
	a.x++;
	a.y = 0;
	printf("numatlast:%d\n", a.x);
	return (a);
}
	
void	handle_signal(int signal)
{
	//static	int num = 0;
	static int	i = 0;
	printf("signal:%d\n", signal);
	if (signal > 0 && signal < 40) {
		counter(1, 2);
		my_putstr("Enemy connected\n");
		i++;
		printf("i:%d\n", i);
	}
}

struct sigaction	*signals(void)
{
	int	i;
	struct sigaction *new_action;
	int	signals[9] = {17, 16, 3, 10, 12, 30, 31, PI};

	new_action = malloc(sizeof(struct sigaction));
	new_action->sa_handler = &handle_signal;
	for (i = 0; signals[i] != PI; i++) {
		if (sigaction(signals[i], new_action, NULL) < 0) {
			return(NULL);
		}
	}
	return (new_action);
}

int	who_sig_me(char **user1_map, char **user2_map,  int ac, int pid)
{
	struct sigaction	*new_action;
	char			*a = NULL;
	
	new_action = signals();
	if (new_action == NULL)
		return (84);
	kill(pid, SIGUSR2);
	while (1) {
		print_map(user1_map, user2_map, ac);
		a = get_next_line(0);
		hit(a, pid);
		pause();
		printf("yea\n");
	}
	return (0);
}
