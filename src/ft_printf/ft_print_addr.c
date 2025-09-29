/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_addr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaida <lgaida@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 15:23:45 by lgaida            #+#    #+#             */
/*   Updated: 2025/06/25 21:39:58 by lgaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdint.h>
#include <unistd.h>

static void	ft_putaddr(unsigned long addr, char *base, int *count);
static void	ft_putstr(char *s);

int	ft_print_addr(va_list *args)
{
	void	*addr;
	char	*base;
	int		count;

	addr = va_arg(*args, void *);
	if (addr == NULL)
	{
		ft_putstr("(nil)");
		return (5);
	}
	base = "0123456789abcdef";
	ft_putstr("0x");
	count = 2;
	ft_putaddr((unsigned long)addr, base, &count);
	return (count);
}

static void	ft_putaddr(unsigned long addr, char *base, int *count)
{
	char	c;

	if (addr / 16 != 0)
		ft_putaddr((addr / 16), base, count);
	c = base[addr % 16];
	write(1, &c, 1);
	(*count)++;
}

static void	ft_putstr(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}
