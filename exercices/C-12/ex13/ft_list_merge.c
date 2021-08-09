#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*current;

	if (begin_list1 == 0 || begin_list2 == 0)
		return ;
	else if (*begin_list1 == 0)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	current = *begin_list1;
	while (current->next != 0)
		current = current->next;
	if (begin_list2 != 0)
		current->next = begin_list2;
}
