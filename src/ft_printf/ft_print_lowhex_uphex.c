/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lowhex_uphex.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaida <lgaida@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 15:33:43 by lgaida            #+#    #+#             */
/*   Updated: 2025/06/25 21:16:15 by lgaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

static void	ft_putnbr_base(unsigned int n, char *base, int *count);

int	ft_print_lowhex(va_list *args)
{
	unsigned int	nbr;
	char			*base;
	int				count;

	nbr = va_arg(*args, unsigned int);
	base = "0123456789abcdef";
	count = 0;
	ft_putnbr_base(nbr, base, &count);
	return (count);
}

int	ft_print_uphex(va_list *args)
{
	unsigned int	nbr;
	char			*base;
	int				count;

	nbr = va_arg(*args, unsigned int);
	base = "0123456789ABCDEF";
	count = 0;
	ft_putnbr_base(nbr, base, &count);
	return (count);
}

static void	ft_putnbr_base(unsigned int n, char *base, int *count)
{
	char	c;

	if (n / 16 != 0)
		ft_putnbr_base((n / 16), base, count);
	c = base[n % 16];
	write(1, &c, 1);
	(*count)++;
}
