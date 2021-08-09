#ifndef FT_LIST_H
# define FT_LIST_H

typedef struct s_list
{
	struct s_list	*next;
	void			*data;
}	t_list;

t_list	*ft_create_elem(void *data);
void	reverse_list(t_list *begin_list);
void	re_point_list(t_list *begin_list);

#endif