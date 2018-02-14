/*
** EPITECH PROJECT, 2018
** bs_NAVI
** File description:
** by Oriol
*/

#include "list.h"

struct coord_t	counter(int x, int y)
{
	static struct coord_t	a = {.y = 0, .x = 0}; 
	
	a.x = a.x + x;
	a.y = a.y + y;
	return (a);
}
	
void	handle_signal(int signal)
{
	//printf("signal:%d\n", signal);
	if (signal == 30 || signal == 10 || signal == 16) 
		counter(1, 0);
	else if (signal == 31 || signal == 12 || signal == 17)
		counter(0, 1);
	//my_putstr("Enemy connected\n");
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
	struct coord_t		num;
	
	new_action = signals();
	if (new_action == NULL)
		return (84);
	while (1) {
		print_map(user1_map, user2_map, ac);
		a = get_next_line(0);
		hit(a, pid);
		num = counter(0, 0);
		printf("x:%d, y:%d\n", num.x, num.y);
		pause();
		printf("yea\n");
	}
	return (0);
}
