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

void	handle_signal(int signal)
{
	char	*a;
	//static	int num = 0;
	static int	i = 0;
	if (signal > 0 && signal < 35) {
		my_putstr("Signal ");
		a = strsignal(signal);	
		if (my_strcmp(a, "Quit") == 1)
			exit(0);
		if (my_strcmp(a, "User") == 1) {
			printf("hehe\n");
			i++;
		}
		my_put_nbr(i);
		my_putstr(a);
		my_putstr(" recieved from ");
		my_put_nbr((int)getpid());
	}
}

int	who_sig_me()
{
	struct sigaction	new_action;
	int			*signals;
	int			i;
	
	my_put_nbr((int)getpgid(getpid()));
	signals = malloc(sizeof(int) * 4);
	signals[0] = 17;
	signals[1] = 16;
	signals[2] = 3;
	signals[3] = PI;
	new_action.sa_handler = &handle_signal;
	for (i = 0; signals[i] != PI; i++) {
		if (sigaction(signals[i], &new_action, NULL) < 0) {
			printf("out:%d\n", i);
			free(signals);
			return(0);
		}
	}
	while (1) {
		
	}
	return (0);
}
        /*
	while (1) {
		new_action.sa_handler = termination_handler;
		sigemptyset (&new_action.sa_mask);
		new_action.sa_flags = 0;
		
		sigaction (SIGINT, NULL, &old_action);
		if (old_action.sa_handler != SIG_IGN)
		if (old_action.sa_handler != SIG_IGN)
			sigaction (SIGINT, &new_action, NULL);
		sigaction (SIGHUP, NULL, &old_action);
		if (old_action.sa_handler != SIG_IGN)
			sigaction (SIGHUP, &new_action, NULL);
		sigaction (SIGTERM, NULL, &old_action);
		if (old_action.sa_handler != SIG_IGN)
			sigaction (SIGTERM, &new_action, NULL);
	}
		
	printf("uu\n");
	if (sigaction(SIGKILL, &sa, NULL) == -1) {
		perror("Cannot handle SIGKILL"); // Will always happen
		printf("You can never handle SIGKILL anyway...\n");
		
	}
	

int	main(int ac, char **av)
{
	int	i;
	printf("%d\n",ac);
	for (i = 0; i != ac; i++)
		printf("av:%s\n", av[i]);
	//proces_info();
	//if (ac == 2)
	//kill_it(my_get_nbr(av[1]));
	if (ac == 4)
		kill(my_get_nbr(av[3]), SIGUSR1);
	if (ac == 3 || ac == 4)
		who_sig_me(my_get_nbr(av[1]), my_get_nbr(av[2]));
}
	*/
