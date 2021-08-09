#include "ft_list.h"

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*current;
	void	*tmp_data;

	current = begin_list;
	if (current == 0 || current->next == 0)
		return ;
	else if (current->next->next == 0)
	{
		tmp_data = begin_list->data;
		begin_list->data = begin_list->next->data;
		begin_list->next->data = tmp_data;
		return ;
	}
	else
		re_point_list(begin_list);
}

void	re_point_list(t_list *begin_list)
{
	t_list	*current;
	t_list	*second;
	t_list	*last;
	t_list	*pre_last;
	void	*tmp_data;

	current = begin_list;
	second = current->next;
	while (current->next->next != 0)
		current = current->next;
	pre_last = current;
	last = current->next;
	reverse_list(begin_list);
	tmp_data = begin_list->data;
	begin_list->data = last->data;
	last->data = tmp_data;
	begin_list->next = pre_last;
	second->next = last;
	last->next = 0;
}

void	reverse_list(t_list *begin_list)
{
	t_list	*current;
	t_list	*previous;
	t_list	*next;

	current = begin_list;
	previous = 0;
	while (current != 0)
	{
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
}
