#include "ft_list.h"
#include <stdlib.h>

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*current;
	t_list	*prev;

	current = begin_list;
	while (current != 0)
	{
		prev = current;
		current = current->next;
		if (prev->data != 0)
			(*free_fct)(prev->data);
		free(prev);
	}
}
