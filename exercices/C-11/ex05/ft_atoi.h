#ifndef FT_ATOI_H

# define FT_ATOI_H

typedef struct s_atoi_res
{
	long	num;
	char	sign;
}	t_atoi_res;

t_atoi_res	ft_atoi(char *str);
long		find_num(char *str);
int			ft_isspace(char c);
int			ft_isnum(char c);
int			ft_issign(char c);

#endif