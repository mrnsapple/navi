/*
** EPITECH PROJECT, 2018
** bs_NAVI
** File description:
** by Oriol
*/

#include "list.h"

int	pid_2 = 0;

struct coord_t	counter(int x, int y, int z)
{
	static struct coord_t	a = {.y = 0, .x = 0};
	
	if (a.x == 0 && a.y == 0)
		my_putstr("\n\nenemy_connected\n");
	if (z != 0) {
		a.y = 0;
		a.x = 0;
	}
	a.x = a.x + x;
	a.y = a.y + y;
	printf("a.y:%d,a.x:%d\n", a.y, a.x);
	return (a);
}
	
void	handle_signal(int signal, siginfo_t *siginfo, void *context)
{
	pid_2 = siginfo->si_pid;

        printf("send_pid%d\n", pid_2);
	//printf("signal:%d\n", signal);
	if (signal == 30 || signal == 10 || signal == 16) 
		counter(1, 0, 0);
	else if (signal == 31 || signal == 12 || signal == 17)
		counter(0, 1, 0);
	//my_putstr("Enemy connected\n");
}

struct sigaction	*signals(int ac, int pid)
{
	int	i;
	struct sigaction *new_action;
	int	signals[9] = {17, 16, 3, 10, 12, 30, 31, PI};
		
	new_action = malloc(sizeof(struct sigaction));
	//new_action->sa_handler = &handle_signal;
	new_action->sa_sigaction = &handle_signal;
	new_action->sa_flags = SA_SIGINFO;
	for (i = 0; signals[i] != PI; i++) {
		if (sigaction(signals[i], new_action, NULL) < 0) {
			return(NULL);
		}
	}
	if (ac == 3) {
		kill(pid, SIGUSR1);
		counter(0, 0 , 1);
	}
	return (new_action);
}

int	wait_1_signal(int ac, int num_print)
{
	if (ac == 2)
		for (num_print = pause();
		     num_print != -1; num_print = pause());
	num_print = ac;
	return (num_print);
}

int	who_sig_me(char **user1_map, char **user2_map,  int ac, int pid)
{
	struct sigaction	*new_action;
	char			*a = NULL;
	struct coord_t		num;
	int	num_print = ac;
	
	new_action = signals(ac, pid);
	if (new_action == NULL)
		return (84);
	num_print = wait_1_signal(ac, num_print);
	while (1) {
		print_map(user1_map, user2_map, ac, &num_print);
		//printf("pid2:%d\n", pid_2);
		a = get_next_line(0);
		if (ac == 3)
			pid_2 = pid;
		hit(a, pid_2);
		num = counter(0, 0, 0);
		printf("x:%d, y:%d\n", num.x, num.y);
	}
	return (0);
}
