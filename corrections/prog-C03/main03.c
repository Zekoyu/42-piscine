#include "../ex03/ft_strncat.c"

#include <stdio.h>
#include <string.h>

int	main(void)
{

	printf("=================== EX 03 ========================\n");

	char test1[40] = "Salut";
	char test1_c[40] = "Salut";

	char test2[40] = "test";
	char test2_c[40] = "test";

	char test3[40] = "Ca marche ?\n";
	char test3_c[40] = "Ca marche ?\n";

	char test4[40] = "Ou";
	char test4_c[40] = "Ou";

	printf("Input(\"Salut\", \" ca va ?\", 4) | Return:%s<== (Expected:%s<==)\n", ft_strncat(test1, " ca va ?", 4), strncat(test1_c, " ca va ?", 4));
	printf("Input(\"test\", \"\", 1) | Return:%s (Expected:%s)\n", ft_strncat(test2, "", 1), strncat(test2_c, "", 1));
	printf("Input(\"Ca marche ?\\n\", \"Ca marche   \", 0) | Return:%s<==  (Expected:%s<==)\n", ft_strncat(test3, "Ca marche   ", 0), strncat(test3_c, "Ca marche   ", 0));
	printf("Input(\"Ou\", \"Ou pas\", 5) | Return:%s (Expected:%s)\n", ft_strncat(test4, "Ou pas", 5), strncat(test4_c, "Ou pas", 5));
}
