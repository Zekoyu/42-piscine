#include "../ex04/ft_str_is_lowercase.c"

#include<stdio.h>

int main()
{
	printf("=================== EX 04 ========================\n");

	printf("Is lowercase(\"\") | Output: %d\n", ft_str_is_lowercase(""));
	printf("Is lowercase(\"c est bon\") | Output: %d\n", ft_str_is_lowercase("c est bon"));
	printf("Is lowecase(\"Salut\") | Output: %d\n", ft_str_is_lowercase("Salut"));
	printf("Is lowercase(\"enfin\") | Output: %d\n", ft_str_is_lowercase("enfin"));
}
