#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref,
		int (*cmpf)(void *, void *))
{
	t_btree	*res;

	res = 0;
	search_btree_recursive(root, data_ref, cmpf, &res);
	if (res == 0)
		return (0);
	return (res->item);
}

void	search_btree_recursive(t_btree *node, void *data_ref,
		int (*cmpf)(void *, void *), t_btree **res)
{
	if (node != 0)
	{
		if (*res == 0 && node->left != 0)
		{
			search_btree_recursive(node->left, data_ref, cmpf, res);
		}
		if (*res == 0 && (*cmpf)(data_ref, node->item) == 0)
			*res = node;
		if (*res == 0 && node->right != 0)
		{
			search_btree_recursive(node->right, data_ref, cmpf, res);
		}
	}
}
