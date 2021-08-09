#include "ft_btree.h"

// Apply to root first
// Then left (root = left)
// Then right (root = right)
void	btree_apply_prefix(t_btree *root, void (*applyf)(void *))
{
	if (root != 0)
	{
		(*applyf)(root->item);
		if (root->left != 0)
		{
			btree_apply_prefix(root->left, applyf);
		}
		if (root->right != 0)
		{
			btree_apply_prefix(root->right, applyf);
		}
	}
}
