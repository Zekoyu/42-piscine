#include "../ex07/ft_putnbr.c"

#include <stdio.h>

int	main(void)
{
	printf("=================== EX 07 ========================\n");
	printf("Put nbr 42:\n");
	ft_putnbr(42);
	printf("<==FINITO\n");
	printf("Put nbr -2147483648 (int min):\n");
    ft_putnbr(-2147483648);
    printf("<==FINITO\n");
	printf("Put nbr -2054:\n");
    ft_putnbr(-2054);
	printf("<==FINITO\n");
	printf("Put nbr 2147483647 (int max):\n");
    ft_putnbr(2147483647);
    printf("<==FINITO\n");
	printf("Put nbr 0:\n");
    ft_putnbr(0);
    printf("<==FINITO\n");
}
