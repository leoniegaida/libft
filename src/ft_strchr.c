/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaida <lgaida@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 19:01:37 by lgaida            #+#    #+#             */
/*   Updated: 2025/06/03 17:39:07 by lgaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*str;
	unsigned char	chr;
	size_t			i;

	str = (unsigned char *)s;
	chr = (unsigned char)c;
	i = 0;
	while (str[i])
	{
		if (str[i] == chr)
		{
			return ((char *)&str[i]);
		}
		i++;
	}
	if (chr == '\0')
	{
		return ((char *)&str[i]);
	}
	return (NULL);
}
