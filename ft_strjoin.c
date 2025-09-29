/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaida <lgaida@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 19:02:16 by lgaida            #+#    #+#             */
/*   Updated: 2025/06/03 17:40:03 by lgaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t			s1_len;
	size_t			s2_len;
	char			*str;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = malloc(s1_len + s2_len + 1);
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, s1_len);
	ft_memcpy(&str[s1_len], s2, s2_len);
	str[s1_len + s2_len] = '\0';
	return (str);
}
