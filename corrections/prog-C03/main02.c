#include "../ex02/ft_strcat.c"

#include <stdio.h>
#include <string.h>

int	main(void)
{

	printf("=================== EX 02 ========================\n");

	char test1[40] = "Salut";
	char test1_c[40] = "Salut";

	char test2[40] = "test";
	char test2_c[40] = "test";

	char test3[40] = "Ca marche ?\n";
	char test3_c[40] = "Ca marche ?\n";

	char test4[40] = "Ou";
	char test4_c[40] = "Ou";

	printf("Input(\"Salut\", \" ca va ?\") | Return:%s (Expected:%s)\n", ft_strcat(test1, " ca va ?"), strcat(test1_c, " ca va ?"));
	printf("Input(\"test\", \"\") | Return:%s (Expected:%s)\n", ft_strcat(test2, ""), strcat(test2_c, ""));
	printf("Input(\"Ca marche ?\\n\", \"Ca marche   \") | Return:%s<==  (Expected:%s<==)\n", ft_strcat(test3, "Ca marche   "), strcat(test3_c, "Ca marche   "));
	printf("Input(\"Ou\", \"Ou pas\") | Return:%s (Expected:%s)\n", ft_strcat(test4, "Ou pas"), strcat(test4_c, "Ou pas"));
}
