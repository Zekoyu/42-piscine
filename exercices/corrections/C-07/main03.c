#include "../ex03/ft_strjoin.c"
#include <stdio.h>

int main()
{
	printf("================= EX 03 =================\n");

	char *t1[] = {"123", "567"};
	char *t2[] = {"Oui", "Non", "Parfait"};
	char *t3[] = {"Ceci", "est", "un", "test"};
	char *t4[] = {"123"};

	printf("Strjoin (2, {\"123\", \"567\"} \"4\"): %s  (Expect: 1234567)\n", ft_strjoin(2, t1, "4"));
	printf("Strjoin (3, {\"Oui\", \"Non\", \"Parfait\"}, \"=-=\"): %s  (Expect: Oui=-=Non=-=Parfait)\n", ft_strjoin(3, t2, "=-="));
	printf("Strjoin (3, {\"Ceci\", \"est\", \"un\", \"test\"}, \" \"): %s  (Expect: Ceci est un)\n", ft_strjoin(3, t3, " "));
	printf("Strjoin (0, {\"123\"}, \"_\"): %s  (Expect: )\n", ft_strjoin(0, t4, "_"));

}
