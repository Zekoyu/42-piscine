#include <unistd.h>

void	ft_putnbr_base(int nbr, char *base);
int		is_valid_base(char *str);

int	is_valid_base(char *str)
{
	int		i;
	int		j;
	char	values[256];

	i = 0;
	while (++i <= 256)
		values[i - 1] = '\0';
	i = 0;
	while (str[i] != '\0' && i < 256)
	{
		values[i] = str[i];
		if (str[i] == '+' || str[i] == '-')
			return (0);
		j = 0;
		while (++j <= 256)
		{
			if (values[j - 1] == str[i] && j - 1 != i)
			{
				return (0);
			}
		}	
		i++;
	}
	return (1);
}

unsigned int	set_pos_if_neg(int nbr)
{
	unsigned int	pos_num;

	if (nbr < 0)
	{
		pos_num = (unsigned int) -nbr;
		write(1, "-", 1);
	}
	else
		pos_num = (unsigned int) nbr;
	return (pos_num);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int				bsize;
	int				i;
	int				j;
	unsigned int	pnum;
	char			result[40];

	if (nbr == 0)
		write (1, &base[0], 1);
	j = -1 ;
	while (++j < 40)
		result[j] = '\0';
	i = 0;
	bsize = 0;
	while (base[i++] != '\0')
		bsize++;
	if (!is_valid_base(base) || bsize <= 1)
		return ;
	pnum = set_pos_if_neg(nbr);
	while (pnum > 0)
	{
		result[--j] = base[pnum % bsize];
		pnum /= bsize;
	}
	while (j < 40)
		write (1, &result[j++], 1);
}
