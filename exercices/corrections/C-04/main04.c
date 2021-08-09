#include "../ex04/ft_putnbr_base.c"

#include <stdio.h>

int	main(void)
{

	printf("=================== EX 04 ========================\n");

	printf("Put_nbr_base (-2147483648, \"0123456789ABCDEF\") (expect -80000000):\n");
	ft_putnbr_base(-2147483648, "0123456789ABCDEF");
    printf("\n");

	printf("Put_nbr_base (2147483647, \"0123456789ABCDEF\") (expect 7FFFFFFF):\n");
	ft_putnbr_base(2147483647, "0123456789ABCDEF");
    printf("\n");

	printf("Put_nbr_base (123454321, \"0123456789\") (expect 123454321):\n");
	ft_putnbr_base(123454321, "0123456789");
    printf("\n");

	printf("Put_nbr_base (1, \"001\") (expect nothing):\n");
	ft_putnbr_base(1, "001");
    printf("\n");

	printf("Put_nbr_base (-1234, \"01\") (expect -10011010010):\n");
	ft_putnbr_base(-1234, "01");
    printf("\n");

	printf("Put_nbr_base (-1234, \"0\") (expect nothing):\n");
	ft_putnbr_base(-1234, "0");
    printf("\n");

	printf("Put_nbr_base (52152, \"0123456789ABC\") (expect 1A979):\n");
	ft_putnbr_base(52152, "0123456789ABC");
    printf("\n");
	
	printf("Put_nbr_base (0, \"01\") (expect 0 (?)):\n");
	ft_putnbr_base(0, "01");
    printf("\n");
}
