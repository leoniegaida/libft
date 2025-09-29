/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaida <lgaida@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:27:06 by lgaida            #+#    #+#             */
/*   Updated: 2025/06/24 18:58:49 by lgaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

int	ft_print_char(va_list *args)
{
	char	c;

	c = (char)va_arg(*args, unsigned int);
	write(1, &c, 1);
	return (1);
}
