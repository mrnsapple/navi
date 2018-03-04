/*
** EPITECH PROJECT, 2018
** bs_NAVI
** File description:
** by Oriol
*/

#include "list.h"

int     is_there_ship(struct coord_t num, char **user1_map, char **user2_map, int ac);
char    **is_there_ship_atack(struct coord_t num,
			      char **user1_map, char **user2_map, char *a);
int     you_won(struct coord_t num);
int     wait_1_signal(int ac, int num_print);
int     who_sig_me(char **user1_map, char **user2_map,  int ac, int pid);

int	pid_2 = 0;

struct coord_t	counter(int x, int y, int z)
{
	static struct coord_t	a = {.y = 0, .x = 0, .z = 0};

	if (z == 0) {
		a.y = 0;
		a.x = 0;
		a.z = 0;
	}
	a.x = a.x + x;
	a.y = a.y + y;
	if (x == 0 && y == 1 && z == 1 && a.x != 0) {
		a.y--;
		a.z = 3;
	}
	return (a);
}

void	handle_signal(int signal, siginfo_t *siginfo, void *context)
{
	pid_2 = siginfo->si_pid;
	if (signal == 30 || signal == 10 || signal == 16) 
		counter(1, 0, 1);
	else if (signal == 31 || signal == 12 || signal == 17)
		counter(0, 1, 1);
}

void	handle(int signal)
{
	if (signal == 30 || signal == 10 || signal == 16) 
		counter(1, 0, 1);
	else if (signal == 31 || signal == 12 || signal == 17)
		counter(0, 1, 1);
}

struct sigaction	*signals(int ac, int pid)
{
	int			i;
	struct sigaction	*new_action;
	int			signals[9] = {17, 16, 3, 10, 12, 30, 31, PI};

	new_action = malloc(sizeof(struct sigaction));
	new_action->sa_sigaction = &handle_signal;
	new_action->sa_flags = SA_SIGINFO;
	for (i = 0; signals[i] != PI; i++) {
		if (sigaction(signals[i], new_action, NULL) < 0) {
			return(NULL);
		}
	}
	if (ac == 3) {
		kill(pid, SIGUSR1);
		kill(pid, SIGUSR2);
		counter(0, 0 , 0);
	}
	return (new_action);
}


int     who_sig_me(char **user1_map, char **user2_map,  int ac, int pid)
{
	struct sigaction        *new_action;
	char                    *a = NULL;
	struct coord_t          num = {.x = 0, .y = 0};
	int                     num_print = ac;
	int                     ret = 3;
	struct coord_t  value = {.x = 0, .y = 0};

	new_action = signals(ac, pid);
	if (new_action == NULL)
		return (84);
	num_print = wait_1_signal(ac, num_print);
	while (1) {
		num = counter(0, 0, 1);
		is_there_ship_atack(num, user1_map, user2_map, a);
		if (you_won(num) == 0)
			return (0);
		if (ac == 3)
			print_map_board(user1_map, user2_map);
		num = print_map(user1_map, user2_map, ac, &num_print);
		ret = is_there_ship(num, user1_map, user2_map, num_print);
		if (ac == 2)
			print_map_board(user1_map, user2_map);
		if (lose_function(user1_map, pid_2, ret) == 0)
			return (0);
		a = atack(a);
		if (ac == 3)
			pid_2 = pid;
		hit(a, pid_2);
		for (value = counter(0, 0 , 1); value.z != 3;
		     value = counter(0, 0, 1));
	}
	return (0);
}

