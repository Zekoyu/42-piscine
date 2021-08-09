#include "../ex01/ft_strncmp.c"

#include <stdio.h>
#include <string.h>

int	main(void)
{

	printf("=================== EX 01 ========================\n");

	printf("Input(\"salut\", \"salute\", 5) | Return:%d  (Expected:%d)\n", ft_strncmp("salut", "salute", 5), strncmp("salut", "salute", 5));
	printf("Input(\"salute\", \"salut\", 5) | Return:%d  (Expected:%d)\n", ft_strncmp("salute", "salut", 5), strncmp("salute", "salut", 5));
	printf("Input(\"Salut\", \"salut\", 5) | Return:%d  (Expected:%d)\n", ft_strncmp("Salut", "salut", 5), strncmp("Salut", "salut", 5));
	printf("Input(\"test\", \"\", 0) | Return:%d  (Expected:%d)\n", ft_strncmp("test", "", 0), strncmp("test", "", 0));
	printf("Input(\"Ca marche ?\", \"Ca marche\", 15) | Return:%d  (Expected:%d)\n", ft_strncmp("Ca marche ?", "Ca marche", 15), strncmp("Ca marche ?", "Ca marche", 15));
	printf("Input(\"Ou\", \"Ou pas\", 2) | Return:%d  (Expected:%d)\n", ft_strncmp("Ou", "Ou pas", 2), strncmp("Ou", "Ou pas", 2));
	printf("Input(\"\\xc8\", \"\\x01\", 1) | Return:%d  (Expected:%d)\n", ft_strncmp("\xc8", "\x01", 1), strncmp("\xc8", "\x01", 1));
}
