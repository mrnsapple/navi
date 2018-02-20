/*
** EPITECH PROJECT, 2018
**
** File description:
**
*/

#include "list.h"

char	**malloca(int num_ar, int cha)
{
	char	**pwd;
	int	fd;

	pwd = malloc(sizeof(char *) * (num_ar + 2));
	for (fd = 0; fd < num_ar + 2; fd++)
		pwd[fd] = malloc(sizeof(char) * (cha + 5));
	return (pwd);
}

int	**int_malloca(int num_ar, int cha)
{
	int	**pwd;
	int	fd;

	pwd = malloc(sizeof(int *) * (num_ar + 2));
	for (fd = 0; fd < num_ar + 2; fd++)
		pwd[fd] = malloc(sizeof(int));
	return (pwd);
}
