#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*res;
	int	i;
	int	val;

	res = malloc(sizeof (int) * length);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < length)
	{
		val = tab[i];
		res[i] = (*f)(val);
		i++;
	}
	return (res);
}
