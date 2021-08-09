#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item,
		int (*cmpf)(void *, void *))
{
	t_btree	*previous;
	t_btree	*current;

	previous = 0;
	if (*root == 0)
		*root = btree_create_node(item);
	else
	{
		current = *root;
		while (current != 0)
		{
			previous = current;
			if ((*cmpf)(item, current->item) < 0)
				current = current->left;
			else
				current = current->right;
		}
		if ((*cmpf)(item, previous->item) < 0)
			previous->left = btree_create_node(item);
		else
			previous->right = btree_create_node(item);
	}
}
