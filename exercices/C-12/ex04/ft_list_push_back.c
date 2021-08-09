#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*current;

	if (begin_list == 0)
		return ;
	current = *begin_list;
	if (current == 0)
	{
		*begin_list = ft_create_elem(data);
		return ;
	}
	while (current->next != 0)
		current = current->next;
	current->next = ft_create_elem(data);
}
