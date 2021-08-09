#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int		count;
	t_list	*next;

	if (begin_list == 0)
		return (0);
	count = 1;
	next = begin_list->next;
	while (next != 0)
	{
		count++;
		next = next->next;
	}
	return (count);
}
