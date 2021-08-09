#include "../ex08/ft_print_combn.c"

#include <stdio.h>

int	main(void)
{
	printf("=================== EX 08 ========================\n");
	printf("Test avec 1:\n");
	ft_print_combn(1);
	printf("<==FINITO");
	printf("\n\nTest avec 2:\n");
    ft_print_combn(2);
    printf("<==FINITO");
	printf("\n\nTest avec 6:\n");
	ft_print_combn(6);
	printf("<==FINITO");
	printf("\n\nTest avec 9:\n");
	ft_print_combn(9);
	printf("<==FINITO");
}
