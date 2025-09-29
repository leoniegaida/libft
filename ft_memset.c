/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaida <lgaida@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 19:00:35 by lgaida            #+#    #+#             */
/*   Updated: 2025/06/03 17:35:17 by lgaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	a;
	size_t			i;

	ptr = (unsigned char *)s;
	a = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		ptr[i] = a;
		i++;
	}
	return (s);
}
