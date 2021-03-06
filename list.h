/*
** EPITECH PROJECT, 2018
** djek
** File description:
** dekde
*/

#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#ifndef LIST_H_
#define LIST_H_
#define PI	      -84

typedef struct	coord_t
{
	int	x;
	int	y;
	int	z;
}coord_t;
void	free_malloca(int num_a, int cha, char **av);
int	 lose_function(char **user1_map, int pid_2, int ret);
int	 lose(char **map);
int	 hit_return(int ret, int pid);
int	 send_lose(int pid);
void	print_map_board(char **user1, char **user2);
char	*atack(char *a);
struct coord_t  counter(int x, int y, int z);
long	decim_bin(int decimal_num);
int	binaryToDecimal(int n);
int	hit(char *a, int pid);
char	**feed_empty(char **av);
char	**opene(char *av);
char	**insert_map(char *av, char **ptr);
char	**open_function(char	*av);
int	 who_sig_me(char **user1_map, char **user2_map, int ac, int pid);
void	handle_signal(int signal, siginfo_t *siginfo, void *context);
struct coord_t	print_map(char **user1, char **user2, int ac, int *num);

int	my_strcmp(char *pwd, char *line);
int	reduce_place(int place, int num_match);
int	increase_nb_stick(int nb_stick, char **map,
			  int *lines_with, int lines);
int	player_wins(char **map, int lines, int num_match, int *count);
int	are_nb(char *str);
int	are_positive(int lines, int nb_match);
int	get_the_match(int num, int *line, int lines, char **map);
int	 before_the_match(int num, int *count);
int	sticks(char *av, int i);
int	 get_the_line(int count, int *line, int lines, char **map);
char	**game(int lines);
void	print_game(char **game);
char	**print_updated_board_game(int lines, int line,
				   int nb_matches, char **game);
int	my_put_nbr(int nb);
int	out_of_range(int line, int lines, char **map);
char	**ai(char **map, int lines, int num_match);
void	print_player_remove(int nb, int line);
int	 **get_place(int lines, int **game, int **place, int i);
int	 *more_than_1(int *first, int *second);
int	get_rows(int lines, int rows, int i);
char	*get_next_line(int fd);
int	player_win(char **map);
int	ai_win(char **map);
int	 matches_out_of(int num, char *map, int num_match, int *xo);
int	my_get_nbr(char *str);
int	my_putstr_error(char *str);
int	**big_2(int lines_with, int **game, int num_match, int lines);
char	**malloca(int num_ar, int cha);
int	**int_malloca(int num_ar, int cha);
void	error(int ac);
void	my_putchar(char c);
int	my_putstr(char *str);
char	**create_map_base(void);
int	 check_map();
#endif
