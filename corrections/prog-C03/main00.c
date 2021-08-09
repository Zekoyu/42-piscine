#include "../ex00/ft_strcmp.c"

#include <stdio.h>
#include <string.h>

int	main(void)
{

	printf("=================== EX 00 ========================\n");
	
	printf("Input(\"Salut\", \"salut\") | Return:%d  (Expected:%d)\n", ft_strcmp("Salut", "salut"), strcmp("Salut", "salut"));
	printf("Input(\"test\", \"\") | Return:%d  (Expected:%d)\n", ft_strcmp("test", ""), strcmp("test", ""));
	printf("Input(\"Ca marche ?\", \"Ca marche\") | Return:%d  (Expected:%d)\n", ft_strcmp("Ca marche ?", "Ca marche"), strcmp("Ca marche ?", "Ca marche"));
	printf("Input(\"Ou\", \"Ou pas\") | Return:%d  (Expected:%d)\n", ft_strcmp("Ou", "Ou pas"), strcmp("Ou", "Ou pas"));
	printf("Input(\"\\xc8\", \"\\x01\") | Return:%d  (Expected:%d)\n", ft_strcmp("\xc8", "\x01"), strcmp("\xc8", "\x01"));
}
