#include "../ex05/ft_strlcat.c"

#include <stdio.h>
#include <string.h>

int	main(void)
{

	printf("=================== EX 05 ========================\n");

	char test1[40] = "Salut";
	char test1_c[40] = "Salut";

	char test2[40] = "test";
	char test2_c[40] = "test";

	char test3[40] = "Ca marche ?\n";
	char test3_c[40] = "Ca marche ?\n";

	char test4[40] = "Ou";
	char test4_c[40] = "Ou";

	char test5[40] = "Sample using \xc8 and\tother\tcharacters";
	char test5_c[40] = "Sample using \xc8 and\tother\tcharacters";

	char test6[40] = "Un dernier";
	char test6_c[40] = "Un dernier";

	int r1 = ft_strlcat(test1, " ca va ?", 14);
	int r2 = ft_strlcat(test2, "", 4);
	int r3 = ft_strlcat(test3, "Ca marche   ", 0);
	int r4 = ft_strlcat(test4, "Ou pas", 9);
	int r5 = ft_strlcat(test5, "\xc8 it works ? Or not", 10);
	int r6 = ft_strlcat(test6, "pour la route", 11);

	int r1_c = strlcat(test1_c, " ca va ?", 14);
    int r2_c = strlcat(test2_c, "", 4);
    int r3_c = strlcat(test3_c, "Ca marche   ", 0);
	int r4_c = strlcat(test4_c, "Ou pas", 9);
	int r5_c = strlcat(test5_c, "\xc8 it works ? Or not", 10);
	int r6_c = strlcat(test6_c, "pour la route", 11);

	printf("Input(\"Salut\", \" ca va ?\", 14) | Output:%s (return %d) (Expected:%s (return %d))\n", test1, r1, test1_c, r1_c);
	printf("Input(\"test\", \"\", 4) | Output:%s (return %d) (Expected:%s (return %d))\n", test2, r2, test2_c, r2_c);
	printf("Input(\"Ca marche ?\\n\", \"Ca marche   \", 0) | Output:%s<== (return %d)  (Expected:%s<== (return %d))\n", test3, r3, test3_c, r3_c);
	printf("Input(\"Ou\", \"Ou pas\", 9) | Output:%s (return %d) (Expected:%s (return %d))\n", test4, r4, test4_c, r4_c);
	printf("Input(\"Sample using \\xc8 and\\tother\\tcharacters\", \"\\xc8 it works ? Or not\", 10) | Output:%s (return %d) (Expected:%s (return %d))\n", test5, r5, test5_c, r5_c);
	printf("Input(\"Un dernier\", \"pour la route\", 11) | Output:%s (return %d) (Expected:%s (return %d))\n", test6, r6, test6_c, r6_c);

}
