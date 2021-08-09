#include "ft_btree.h"

int	btree_level_count(t_btree *root)
{
	int	res;

	if (root == 0)
		return (0);
	res = 1;
	level_count_recursive(root, 1, &res);
	return (res);
}

void	level_count_recursive(t_btree *node, int count, int *res)
{
	if (node == 0)
		return ;
	if (node->left != 0)
		level_count_recursive(node->left, count + 1, res);
	if (node->right != 0)
		level_count_recursive(node->right, count + 1, res);
	if (count > *res)
		*res = count;
}
