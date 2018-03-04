/*
** EPITECH PROJECT, 2018
** binary
** File description:
** by Oriol and Aimane
*/

long	get_bin_pid(int ac, int pid)
{
	long	binary_pid = 0;
	int	pid_2;

	if (ac == 3) {
		pid_2 = (int)getpid();
		binary_pid = decim_bin(pid_2);
		binary_pid = 100;
		while ( binary_pid > 0) {
			if (binary_pid % 10 == 0) {
				kill(pid, SIGUSR1);
			}
			else {
				kill (pid, SIGUSR2);
                        }
			binary_pid /= 10;
		}
	}
	return (binary_pid);

}

long	decim_bin(int decimal_num)
{
	long	num = (long)decimal_num;
	long	remainder;
	long	base = 1;
	long	binary = 0;
	long	no_of_1s = 0;

	while (num > 0) {
		remainder = num % 2;
		if (remainder == 1)
			no_of_1s++;
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
