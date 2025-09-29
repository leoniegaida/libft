/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaida <lgaida@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 19:03:31 by lgaida            #+#    #+#             */
/*   Updated: 2025/06/03 17:42:11 by lgaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static unsigned int	in_set(char const c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*trimmed;

	start = 0;
	while (s1[start] && in_set(s1[start], set))
	{
		start++;
	}
	end = ft_strlen(s1);
	while (end > start && in_set(s1[end - 1], set))
	{
		end--;
	}
	trimmed = malloc(end - start + 1);
	if (!trimmed)
		return (NULL);
	ft_memcpy (trimmed, &s1[start], end - start);
	trimmed[end - start] = '\0';
	return (trimmed);
}
