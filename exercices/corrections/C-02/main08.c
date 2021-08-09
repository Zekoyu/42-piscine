#include "../ex08/ft_strlowcase.c"

#include<stdio.h>

int main()
{
	printf("=================== EX 08 ========================\n");
	
	char test1[] = "Test";
	char test2[] = "B0njour\n";
	char test3[] = "123?456/789az";

	printf("Lower(\"\") | Output: %s\n", ft_strlowcase(""));
	printf("Lower(\"TeSt\") | Output: %s\n", ft_strlowcase(test1));
	printf("Lower(\"bONJOUR\\n\") | Output: %s<==\n", ft_strlowcase(test2));
	printf("Lower(\"123?456/789az\") | Output: %s\n", ft_strlowcase(test3));
}
