char	*ft_strcapitalize(char *str);
int		is_num(char c);
int		is_alpha(char c);

int	is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	is_alpha(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	capitalized;

	i = 0;
	capitalized = 0;
	while (str[i] != '\0')
	{
		if (is_num(str[i]) == 1 || is_alpha(str[i]) == 1)
		{
			if (capitalized == 0 && (str[i] >= 'a' && str[i] <= 'z'))
				str[i] -= 32;
			else if (capitalized == 1 && (str[i] >= 'A' && str[i] <= 'Z'))
				str[i] += 32;
			capitalized = 1;
		}
		else
			capitalized = 0;
		i++;
	}
	return (str);
}
