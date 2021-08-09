#include "ft_list.h"

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*current;
	t_list	*elem;

	if (begin_list == 0)
		return ;
	current = *begin_list;
	if (current == 0)
	{
		*begin_list = ft_create_elem(data);
		return ;
	}
	if ((*cmp)(data, current->data) < 0)
	{
		elem = ft_create_elem(data);
		*begin_list = elem;
		elem->next = current;
		return ;
	}
	do_the_loop(current, data, cmp);
}

void	do_the_loop(t_list *current, void *data, int (*cmp)())
{
	t_list	*next;
	t_list	*elem;

	next = current->next;
	while (next != 0)
	{
		if ((*cmp)(data, current->data) >= 0 && (*cmp)(data, next->data) <= 0)
		{
			elem = ft_create_elem(data);
			current->next = elem;
			elem->next = next;
			return ;
		}
		current = next;
		next = current->next;
	}
	current->next = ft_create_elem(data);
}
