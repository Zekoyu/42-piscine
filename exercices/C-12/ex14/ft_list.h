#ifndef FT_LIST_H
# define FT_LIST_H

typedef struct s_list
{
	struct s_list	*next;
	void			*data;
}	t_list;

t_list	*ft_create_elem(void *data);
int		t_list_size(t_list *begin_list);
void	swap_elts(t_list *first);

#endif