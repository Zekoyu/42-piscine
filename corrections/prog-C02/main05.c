#include "../ex05/ft_str_is_uppercase.c"

#include<stdio.h>

int main()
{
	printf("=================== EX 05 ========================\n");

	printf("Is upper(\"\") | Output: %d\n", ft_str_is_uppercase(""));
	printf("Is upper(\"EHOH\") | Output: %d\n", ft_str_is_uppercase("EHOH"));
	printf("Is upper(\"OHEH \") | Output: %d\n", ft_str_is_uppercase("OHEH "));
	printf("Is upper(\"Test\") | Output: %d\n", ft_str_is_uppercase("Test"));
}
