#include "../ex09/ft_strcapitalize.c"

#include<stdio.h>

int main()
{
	printf("=================== EX 09 ========================\n");
	
	char test1[] = "salut Ca Ca Bonjour Ca va ?";
	char test2[] = "42mots quarante-deux";
	char test3[] = "; cinquante\net+un";

	printf("Capitalize(\"\") | Output: %s\n", ft_strcapitalize(""));
	printf("Capitalize(\"Salut Ca Ca Bonjour Ca va ?\") | Output: %s\n", ft_strcapitalize(test1));
	printf("Capitalize(\"42mots quarante-deux\") | Output: %s\n", ft_strcapitalize(test2));
	printf("Capitalize(\"; cinquante\\net+un\") | Output: %s\n", ft_strcapitalize(test3));
}
