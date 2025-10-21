/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaida <lgaida@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 20:56:38 by lgaida            #+#    #+#             */
/*   Updated: 2025/10/21 20:56:40 by lgaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "libft.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		writtenchars;

	va_start(args, str);
	i = 0;
	writtenchars = 0;
	while (str[i])
	{
		if (str[i] == '%' && 
			(str[i + 1] == 'c' || str[i + 1] == 's' || str[i + 1] == 'p' || 
				str[i + 1] == 'd' || str[i + 1] == 'i' || str[i + 1] == 'u' || 
				str[i + 1] == 'x' || str[i + 1] == 'X' || str[i + 1] == '%'))
			writtenchars += ft_handle_args(str[++i], &args);
		else
		{
			write(1, &str[i], 1);
			writtenchars++;
		}
		i++;
	}
	va_end(args);
	return (writtenchars);
}
