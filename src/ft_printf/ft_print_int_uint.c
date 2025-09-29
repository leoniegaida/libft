/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_uint.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaida <lgaida@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 15:28:25 by lgaida            #+#    #+#             */
/*   Updated: 2025/06/25 21:15:28 by lgaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

static void	ft_put_int(int nbr, int *count);
static void	ft_put_uint(unsigned int nbr, int *count);

int	ft_print_int(va_list *args)
{
	int	nbr;
	int	count;

	count = 0;
	nbr = va_arg(*args, int);
	ft_put_int(nbr, &count);
	return (count);
}

int	ft_print_uint(va_list *args)
{
	unsigned int	nbr;
	int				count;

	count = 0;
	nbr = va_arg(*args, unsigned int);
	ft_put_uint(nbr, &count);
	return (count);
}

static void	ft_put_int(int nbr, int *count)
{
	long	n;
	char	c;

	n = nbr;
	if (n < 0)
	{
		c = '-';
		write(1, &c, 1);
		(*count)++;
		n = -n;
	}
	if (n / 10 != 0)
		ft_put_int((n / 10), count);
	c = (n % 10) + '0';
	write(1, &c, 1);
	(*count)++;
}

static void	ft_put_uint(unsigned int nbr, int *count)
{
	unsigned long	n;
	char			c;

	n = nbr;
	if (n / 10 != 0)
		ft_put_uint((n / 10), count);
	c = (n % 10) + '0';
	write(1, &c, 1);
	(*count)++;
}
