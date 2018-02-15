/*
** EPITECH PROJECT, 2018
** bs_NAVI
** File description:
** by Oriol
*/

#include "list.h"

struct coord_t	counter(int x, int y)
{
	static struct coord_t	a = {.y = 0, .x = -1};

	a.x = a.x + x;
	if (a.x == 0 && a.y == 0)
		my_putstr("\n\nenemy_connected\n");
	a.y = a.y + y;
	printf("a.y:%d,a.x:%d\n", a.y, a.x);
	return (a);
}
	
void	handle_signal(int signal, siginfo_t *siginfo, void *context)
{
	int sender_pid = siginfo->si_pid;
	
	printf("send_pid%d\n", sender_pid);
	//printf("signal:%d\n", signal);
	if (signal == 30 || signal == 10 || signal == 16) 
		counter(1, 0);
	else if (signal == 31 || signal == 12 || signal == 17)
		counter(0, 1);
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
	printf("flag:%d\n",new_action->sa_flags);
	for (i = 0; signals[i] != PI; i++) {
		if (sigaction(signals[i], new_action, NULL) < 0) {
			return(NULL);
		}
	}
	//if (ac == 3)
	//	kill(pid, SIGUSR1);
	return (new_action);
}

long	get_bin_pid(int ac, int pid)
{
	long	binary_pid = 0;
	int	pid_2;
	
	if (ac == 3) {
		pid_2 = (int)getpid();
		binary_pid = decim_bin(pid_2);
		printf("%ld\n", binary_pid);
		binary_pid = 100;
		while ( binary_pid > 0) {
			printf("binary:%ld\n", binary_pid);
			if (binary_pid % 10 == 0) {
				printf("0\n");
				kill(pid, SIGUSR1);
			}
			else {
				printf("1\n");
				kill (pid, SIGUSR2);
			}
			binary_pid /= 10;
		}
	}
	return (binary_pid);

}
int	who_sig_me(char **user1_map, char **user2_map,  int ac, int pid)
{
	struct sigaction	*new_action;
	char			*a = NULL;
	struct coord_t		num;
	
	get_bin_pid(ac, pid);
	new_action = signals(ac, pid);
	if (new_action == NULL)
		return (84);
	while (1) {
		print_map(user1_map, user2_map, ac);
		a = get_next_line(0);
		hit(a, pid);
		num = counter(0, 0);
		printf("x:%d, y:%d\n", num.x, num.y);
		//pause();
		printf("yea\n");
	}
	return (0);
}
