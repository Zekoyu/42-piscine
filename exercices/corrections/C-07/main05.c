#include "../ex05/ft_split.c"
#include <stdio.h>
#include <stdlib.h>

void print_arr(char **arr)
{
	while (*arr != 0)
	{
		printf("%s<====\n", *arr++);
	}
}

int main()
{
printf("================= EX 05 =================\n");

	printf("Split (\"Salut ceci est un test\", \" \")\n");
	print_arr(ft_split("Salut ceci est un test", " "));

	printf("\nSplit (\"  Test    ?   oui\", \" ?\")\n");
	print_arr(ft_split("  Test    ?   oui", " ?"));

	printf("\nSplit (\"123456\", \"\")\n");
	print_arr(ft_split("123456", ""));

	printf("\nSplit (\"Salut\", \"NULL\")\n");
	print_arr(ft_split("Salut", NULL));

	printf("\nSplit (\"Crackito\", \"ci\")\n");
	print_arr(ft_split("Crackito", "ci"));
	
	printf("\nSplit (\"OMTYM61TkXf1SsCeauh    OJn7NKgmtlc4p72TvlPFTqphbL2qo\", \"DTb\")\n");
	print_arr(ft_split("OMTYM61TkXf1SsCeauh    OJn7NKgmtlc4p72TvlPFTqphbL2qo", "DTb"));
	
	printf("\nSplit (\"Crackito\", \"ci\")\n");
	print_arr(ft_split("Crackito", "ci"));
	
	printf("\nSplit (\"Crackito\", \"ci\")\n");
	print_arr(ft_split("Crackito", "ci"));
}
