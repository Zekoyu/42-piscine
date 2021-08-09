#include "../ex05/ft_str_is_uppercase.c"

#include<stdio.h>

int main()
{
	printf("=================== EX 05 ========================\n");

	printf("Is upper(\"\") | Output: %d\n", ft_str_is_alpha(""));
	printf("Is upper(\"EHOH\") | Output: %d\n", ft_str_is_alpha("EHOH"));
	printf("Is upper(\"OHEH \") | Output: %d\n", ft_str_is_alpha("OHEH "));
	printf("Is upper(\"Test\") | Output: %d\n", ft_str_is_alpha("Test"));
}
