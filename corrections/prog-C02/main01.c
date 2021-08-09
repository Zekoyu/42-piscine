#include "../ex01/ft_strncpy.c"

#include<stdio.h>
#include<string.h>

int	main(void)
{
	printf("=================== EX 01 ========================\n");

	char test1[] = "Hello";
	char test2[] = "Ca va ?";

	char test3[] = "ko";
	char test4[] = "T\ne\ns\nT";

	char test5[] = "Hell";
	char test6[] = "Oui";

	char test1_c[] = "Hello";
    char test2_c[] = "Ca va ?";

    char test3_c[] = "ko";
    char test4_c[] = "T\ne\ns\nT";

    char test5_c[] = "Hell";
    char test6_c[] = "Oui";

	printf("Input: (\"Hello\", \"Ca va ?\", 5) | Output: \n==>%s<==FINITO	(Expected ===%s===)\n\n", ft_strncpy(test1, test2, 5), strncpy(test1_c, test2_c, 5));
	printf("Input: (\"ko\", \"T\\ne\\ns\\nT\", 1) | Output: \n==>%s<==FINITO	(Expected ===%s===)\n\n", ft_strncpy(test3, test4, 1), strncpy(test3_c, test4_c, 1));
	printf("Input: (\"Hell\", \"Oui\", 4) | Output: \n==>%s<==FINITO	(Expected ===%s===)\n", ft_strncpy(test5, test6, 4), strncpy(test5_c, test6_c, 4));
}
