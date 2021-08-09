#include "../ex10/ft_strlcpy.c"

#include<stdio.h>
#include<string.h>

int	main(void)
{
	printf("=================== EX 10 ========================\n");

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

	unsigned int r1 = ft_strlcpy(test1, test2, 5);
    unsigned int r2 = ft_strlcpy(test3, test4, 0);
    unsigned int r3 = ft_strlcpy(test5, test6, 1);

	unsigned int r1_c = strlcpy(test1_c, test2_c, 5);
	unsigned int r2_c = strlcpy(test3_c, test4_c, 0);
	unsigned int r3_c = strlcpy(test5_c, test6_c, 1);

	printf("Input: (\"Hello\", \"Ca va ?\", 5) | \nOutput: ==>%s|Return:%u<==FINITO	(Expected ===%s|Return:%u===)\n\n", test1, r1, test1_c, r1_c);
	printf("Input: (\"ko\", \"T\\ne\\ns\\nT\", 0) | \nOutput: ==>%s|Return:%u<==FINITO	(Expected ===%s|Return:%u===)\n\n", test3, r2, test3_c, r2_c);
	printf("Input: (\"Hell\", \"Oui\", 1) | \nOutput: ==>%s|Return:%u<==FINITO	(Expected ===%s|Return:%u===)\n", test5, r3, test5_c, r3_c);
}
