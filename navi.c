/*
** EPITECH PROJECT, 2018
** navi
** File description:
** by Oriol
*/

#include "list.h"
#include "get_next_line.h"

long	decim_bin(int decimal_num)
{
	long num = (long)decimal_num;
	long remainder;
	long base = 1;
	long binary = 0;
	long no_of_1s = 0;

	while (num > 0) {
		remainder = num % 2;
		/*  To count no.of 1s */
		
	    if (remainder == 1) {
		    no_of_1s++;
	    }
	    binary = binary + remainder * base;
	    num = num / 2;
	    base = base * 10;
	}
	return (binary);	
}

void	printbincharpad(char c)
{
	int	i;
	
	for (i = 7; i >= 0; --i) {
		putchar( (c & (1 << i)) ? '1' : '0' );
	}
	putchar('\n');
}

int binaryToDecimal(int n)
{
    int num = n;
    int dec_value = 0;
    int base = 1;
    int temp = num;
    int last_digit;
    
    while(temp) {
        last_digit = temp % 10;
        temp = temp/10;
	dec_value += last_digit*base;
	base = base*2;
    }
    printf("%d\n", dec_value);
    return dec_value;
}

int	main(int ac, char **av)
{
	char	**user_map;
	char    **user_map_empty;

	if (ac != 2 && ac != 3)
		exit(84);
	my_putstr("my_pid: ");
	my_put_nbr((int)getpid());
	my_putstr("\n");
	if (ac == 2)
		user_map = open_function(av[1]);
	if (ac == 3)
		user_map = open_function(av[2]);
	user_map_empty = feed_empty(user_map);
	if (ac == 3)
		who_sig_me(user_map, user_map_empty, ac, my_get_nbr(av[1]));
	if (ac == 2)
		who_sig_me(user_map, user_map_empty, ac, getpid());
	return (0);
}
	
