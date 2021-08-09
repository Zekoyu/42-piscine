#include "../ex01/ft_recursive_factorial.c"
#include <stdio.h>

int main()
{
printf("================= EX 01 =================\n");

printf("!1 = %d (expect 1)\n", ft_recursive_factorial(1));
printf("!3 = %d (expect 6)\n", ft_recursive_factorial(3));
printf("!0 = %d (expect 1)\n", ft_recursive_factorial(0));
printf("!8 = %d (expect 40320)\n", ft_recursive_factorial(8));


}
