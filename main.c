/*
** EPITECH PROJECT, 2018
** bs_NAVI
** File description:
** by Oriol
*/

#include "list.h"

int	proces_info(void)
{
	if (fork() == 0) {
		my_putstr("PID: ");
		my_put_nbr((int)getpid());
		my_putstr("\nPPID: ");
		my_put_nbr((int)getppid());
		my_putstr("\nPGID: ");
		my_put_nbr((int)getpgid(getpid()));
		 my_putstr("\n");
		 // printf("The child's PID is %d.  The process group ID is %dn",
		 //	(int) getpid(), (int) getpgrp());
	}
	return (0);
}

int	kill_it(int num)
{
	kill(num, SIGQUIT);
	printf("don\n");
	return (0);
}

int	counter(int	i)
{
	static int	num = 0;

	if (i == 1)
		num = 1;
	printf("numatlast:%d\n", num);
	return (num);
}
	
void	handle_signal(int signal)
{
	//static	int num = 0;
	static int	i = 0;
	printf("signal:%d\n", signal);
	if (signal == 16 || signal == 17 || (signal > 0 && signal < 33)) {
		counter(1);
		my_putstr("Enemy connected\n");
		i++;
		printf("i:%d\n", i);
	}
}

struct sigaction	*signals(void)
{
	int	signals[5];
	int	i;
	struct sigaction *new_action;

	new_action = malloc(sizeof(struct sigaction));
	new_action->sa_handler = &handle_signal;
	signals[0] = 17;
	signals[1] = 16;
	signals[2] = 3;
	signals[3] = PI;
	for (i = 0; signals[i] != PI; i++) {
		if (sigaction(signals[i], new_action, NULL) < 0) {
			return(NULL);
		}
	}
	return (new_action);
}
int	who_sig_me(char **user1_map, char **user2_map,  int ac, char *pid_user_1)
{
	struct sigaction	*new_action;
	char			*a;
	
        if (ac == 3) {
		kill(my_get_nbr(pid_user_1), SIGQUIT);
		//kill(my_get_nbr(pid_user_1), SIGUSR1);
	}
	new_action = signals();
	if (new_action == NULL)
		return (84);
	for (int i = 0; user1_map[i] != NULL; i++)
                printf ("map:%s",user1_map[i]);

	while (1) {
		print_map(user1_map, user2_map);
		a = get_next_line(0);
		my_putstr(a);
		pause();
		if (counter(9) == 1)
			printf("yea\n");
	}
	return (0);
}
