#ifndef FT_BTREE_H
# define FT_BTREE_H

typedef struct s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;
}	t_btree;

t_btree	*btree_create_node(void *item);
void	search_btree_recursive(t_btree *node, void *data_ref,
			int (*cmpf)(void *, void *), t_btree **res);

#endif