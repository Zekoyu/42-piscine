#include "../ex07/ft_strupcase.c"

#include<stdio.h>

int main()
{
	printf("=================== EX 07 ========================\n");
	
	char test1[] = "Test";
	char test2[] = "B0njour\n";
	char test3[] = "123?456/789az";

	printf("Upper(\"\") | Output: %s\n", ft_strupcase(""));
	printf("Upper(\"Test\") | Output: %s\n", ft_strupcase(test1));
	printf("Upper(\"Bonjour\\n\") | Output: %s<==\n", ft_strupcase(test2));
	printf("Upper(\"123?456/789az\") | Output: %s\n", ft_strupcase(test3));
}
