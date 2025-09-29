/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaida <lgaida@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 19:03:22 by lgaida            #+#    #+#             */
/*   Updated: 2025/06/03 17:41:51 by lgaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*str;
	unsigned char	chr;
	unsigned char	*last;
	size_t			i;

	str = (unsigned char *)s;
	chr = (unsigned char)c;
	last = NULL;
	i = 0;
	while (str[i])
	{
		if (str[i] == chr)
		{
			last = &str[i];
		}
		i++;
	}
	if (chr == '\0')
	{
		last = &str[i];
	}
	return ((char *)last);
}
