#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;
	t_list			*current;

	current = begin_list;
	i = 0;
	while (i < nbr && current != 0)
	{
		current = current->next;
		i++;
	}
	return (current);
}
