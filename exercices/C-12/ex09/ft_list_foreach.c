#include "ft_list.h"

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list	*current;

	current = begin_list;
	while (current != 0)
	{
		(*f)(current->data);
		current = current->next;
	}
}
