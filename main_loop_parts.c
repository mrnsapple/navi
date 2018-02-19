/*
** EPITECH PROJECT, 2018
** Navi
** File description:
** By Oriol
*/

#include "list.h"
#include "get_next_line.h"

int	lose_function(char **user1_map, int pid_2, int ret)
{
	counter(0, 0, 0);
	if (lose(user1_map) == 0) {
		send_lose(pid_2);
		return (0);
	}
	hit_return(ret, pid_2);
	if (lose(user1_map) == 0) {
		send_lose(pid_2);
		return (0);
	}
	return (1);
}
	
