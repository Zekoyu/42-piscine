#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *src)
{
	char	*s;

	s = src;
	while (*s)
		s++;
	return (s - src);
}

char	*ft_strdup(char *src)
{
	char	*res;
	int		i;
	int		src_len;

	src_len = ft_strlen(src);
	res = (malloc(sizeof(char) * (src_len + 1)));
	i = 0;
	while (i < (src_len + 1))
	{
		res[i] = src[i];
		i++;
	}
	return (res);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*res;

	res = malloc(sizeof(t_stock_str) * (ac + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		res[i].size = ft_strlen(av[i]);
		res[i].str = av[i];
		res[i].copy = ft_strdup(av[i]);
		i++;
	}
	res[i].str = 0;
	return (res);
}
