/*
** EPITECH PROJECT, 2018
** binary
** File description:
** by Oriol
*/

long    get_bin_pid(int ac, int pid)
{
        long    binary_pid = 0;
	int     pid_2;

        if (ac == 3) {
                pid_2 = (int)getpid();
                binary_pid = decim_bin(pid_2);
                //printf("%ld\n", binary_pid);
                binary_pid = 100;
                while ( binary_pid > 0) {
			// printf("binary:%ld\n", binary_pid);
                        if (binary_pid % 10 == 0) {
                                //printf("0\n");
                                kill(pid, SIGUSR1);
                        }
                        else {
                              	//printf("1\n");
                                kill (pid, SIGUSR2);
                        }
                        binary_pid /= 10;
	        }
	}
	return (binary_pid);

}
long    decim_bin(int decimal_num)
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
void    printbincharpad(char c)
{
        int     i;

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
    //printf("%d\n", dec_value);
    return dec_value;
}

