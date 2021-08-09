#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list	*elem;

	elem = malloc (sizeof (t_list));
	if (elem == NULL)
		return (NULL);
	elem->next = NULL;
	elem->data = data;
	return (elem);
}
