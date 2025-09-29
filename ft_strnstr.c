/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaida <lgaida@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 19:03:14 by lgaida            #+#    #+#             */
/*   Updated: 2025/06/03 17:41:35 by lgaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	little_len;

	if (little[0] == '\0')
	{
		return ((char *)big);
	}
	little_len = ft_strlen(little);
	i = 0;
	while (big[i] && i + little_len <= len)
	{
		j = 0;
		while (little[j] && little[j] == big[i + j])
		{
			j++;
		}
		if (little[j] == '\0')
		{
			return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
