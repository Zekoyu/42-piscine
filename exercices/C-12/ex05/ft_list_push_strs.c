#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	int		i;
	t_list	*elem;
	t_list	*begin_list;

	if (size == 0)
		return (0);
	i = 0;
	begin_list = ft_create_elem(strs[i]);
	elem = begin_list;
	i++;
	while (i < size)
	{
		elem = ft_create_elem(strs[i]);
		elem->next = begin_list;
		begin_list = elem;
		i++;
	}
	return (begin_list);
}
