#include "../ex00/ft_strcpy.c"

#include<stdio.h>

int	main(void)
{
	printf("=================== EX 00 ========================\n");

	char test1[] = "Bonjour";
	char test2[] = "Ca va ?";

	char test3[] = "";
	char test4[] = "T\ne\ns\nT";

	printf("Input: (\"Bonjour\", \"Ca va ?\") | Output: \n==>%s<==FINITO\n\n", ft_strcpy(test1, test2));
	printf("Input: (\"\", \"T\\ne\\ns\\nT\") | Output: \n==>%s<==FINITO\n\n", ft_strcpy(test3, test4));
}
