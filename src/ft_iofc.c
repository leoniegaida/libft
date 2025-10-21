int	ft_iofc(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (-2);
	while (str[i])
	{
		if (str[i] == c)
		{
			return (i);
		}
		i++;
	}
	if (c == '\0')
	{
		return (i);
	}
	return (-1);
}
