#include "../ex00/ft_iterative_factorial.c"
#include <stdio.h>

int main()
{
printf("================= EX 00 =================\n");

printf("!1 = %d (expect 1)\n", ft_iterative_factorial(1));
printf("!-1 = %d (expect 0)\n", ft_iterative_factorial(-1));
printf("!-15 = %d (expect 0)\n", ft_iterative_factorial(-15));
printf("!3 = %d (expect 6)\n", ft_iterative_factorial(3));
printf("!0 = %d (expect 1)\n", ft_iterative_factorial(0));
printf("!8 = %d (expect 40320)\n", ft_iterative_factorial(8));


}
