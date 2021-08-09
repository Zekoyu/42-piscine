int	ft_atoi_base(char *str, char *base);
int	find_num(char *str);
int	ft_atoi(char *str);
int	char_is_in_base(char c, char *base);
int	index_of(char c, char *str);

int	index_of(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	return (i);
}

int	is_valid_base(char *base)
{
	int		i;
	int		j;
	char	values[256];

	i = 0;
	while (++i <= 256)
		values[i - 1] = '\0';
	i = 0;
	while (base[i] != '\0' && i < 256)
	{
		values[i] = base[i];
		if (base[i] == '+' || base[i] == '-'
			|| (base[i] >= 9 && base[i] <= 13) || base [i] == ' ')
			return (0);
		j = 0;
		while (++j <= 256)
		{
			if (values[j - 1] == base[i] && j - 1 != i)
				return (0);
		}
		i++;
	}
	if (base[i] == '\0' && i <= 1)
		return (0);
	return (1);
}

//On prend le nombre a l'envers, on multiplie son index dans la base
// par la taille de la base^index du chiffre
// On additionne tous les resultats = notre nombre en base 10 

unsigned int	base_to_dec(char *numstr, char *base)
{
	int					i;
	unsigned long int	pow;
	unsigned int		result;
	unsigned long int	bsize;

	bsize = 0;
	pow = 1;
	i = 0;
	result = 0;
	while (base[bsize] != '\0')
		bsize++;
	while (numstr[i] != '\0' && char_is_in_base(numstr[i], base))
		i++;
	while (--i >= 0)
	{
		result += index_of(numstr[i], base) * ((bsize * pow) / bsize);
		pow *= bsize;
	}
	return (result);
}

int	char_is_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (c == base[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	i;

	sign = 1;
	if (!is_valid_base(base))
		return (0);
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (!(str[i] == '+' || str[i] == '-') && !char_is_in_base(str[i], base))
		return (0);
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '+')
			sign *= 1;
		else if (str[i] == '-')
			sign *= -1;
		i++;
	}
	if (!char_is_in_base(str[i], base))
		return (0);
	return (base_to_dec(&str[i], base) * sign);
}
