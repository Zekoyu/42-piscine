#include "../ex00/ft_strdup.c"
#include <stdio.h>

int main()
{
printf("================= EX 00 =================\n");

	char t1[] = "1234";
	char t2[] = "";
	char t3[] = "\xc8\tOui 123456789012345678901234567890i";
	char t4[] = "OK ?";
		
	char *t1_d = ft_strdup(t1);
	char *t2_d = ft_strdup(t2);
	char *t3_d = ft_strdup(t3);
	char *t4_d = ft_strdup(t4);
	
	printf("Str dup (\"1234\") (%p) : %s (%p)\n", t1, t1_d, t1_d);
	printf("Str dup (\"\") (%p) : %s (%p)\n", t2, t2_d, t2_d);
	printf("Str dup (\"\\xc8\\tOui 123456789012345678901234567890i\") (%p) : %s (%p)\n", t3, t3_d, t3_d);
	printf("Str dup (\"OK ?\") (%p) : %s (%p)\n", t4, t4_d, t4_d);

}
