/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaida <lgaida@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 20:56:11 by lgaida            #+#    #+#             */
/*   Updated: 2025/10/21 20:56:15 by lgaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int	ft_handle_args(char spec, va_list *args)
{
	if (spec == 'c')
		return (ft_print_char(args));
	else if (spec == 's')
		return (ft_print_str(args));
	else if (spec == 'p')
		return (ft_print_addr(args));
	else if (spec == 'd' || spec == 'i')
		return (ft_print_int(args));
	else if (spec == 'u')
		return (ft_print_uint(args));
	else if (spec == 'x')
		return (ft_print_lowhex(args));
	else if (spec == 'X')
		return (ft_print_uphex(args));
	else if (spec == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (0);
}
