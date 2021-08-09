#include "ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*current;
	t_list	*index;
	void	*tmp;
	int		i;

	i = 0;
	if (begin_list == 0 || *begin_list == 0)
		return ;
	index = *begin_list;
	while (index->next != 0)
	{
		current = *begin_list;
		while (current->next != 0)
		{
			if ((*cmp)(current->data, current->next->data) > 0)
			{
				tmp = current->data;
				current->data = current->next->data;
				current->next->data = tmp;
			}
			current = current->next;
		}
		index = index->next;
	}
}
