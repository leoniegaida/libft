#include "libft.h"

static int	is_valid(char *base)
{
	int	i;
	int	j;

	if (ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| (base[i] >= 9 && base[i] <= 13))
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	get_value(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	if (!is_valid(base))
		return (0);
	while ((*str >= 9 && *str <= 13) || *str == ' '
		|| *str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (get_value(*str, base) != -1)
	{
		result = result * ft_strlen(base) + get_value(*str, base);
		str++;
	}
	return (result * sign);
}