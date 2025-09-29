/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaida <lgaida@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 18:59:49 by lgaida            #+#    #+#             */
/*   Updated: 2025/06/03 17:34:08 by lgaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	count_digits(long int nbr)
{
	size_t	len;

	len = 0;
	if (nbr <= 0)
		len++;
	while (nbr)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

static void	fill_str(char *str, long int nbr)
{
	int	i;

	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	if (nbr >= 10)
	{
		fill_str(str, nbr / 10);
	}
	i = 0;
	while (str[i] != '\0')
		i++;
	str[i] = (nbr % 10) + '0';
}

char	*ft_itoa(int n)
{
	char		*str;
	long int	nbr;
	size_t		str_len;

	nbr = n;
	str_len = count_digits(nbr);
	str = malloc(str_len + 1);
	if (!str)
		return (NULL);
	ft_bzero(str, str_len + 1);
	fill_str(str, nbr);
	return (str);
}
