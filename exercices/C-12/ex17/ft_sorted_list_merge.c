#include "ft_list.h"

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
		int (*cmp)())
{
	ft_list_mergee1(begin_list1, begin_list2);
	ft_list_sorte1(begin_list1, cmp);
}

void	ft_list_mergee1(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*current;

	if (begin_list1 == 0 || *begin_list1 == 0 || begin_list2 == 0)
		return ;
	current = *begin_list1;
	while (current->next != 0)
		current = current->next;
	if (begin_list2 != 0)
		current->next = begin_list2;
}

void	ft_list_sorte1(t_list **begin_list, int (*cmp)())
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
