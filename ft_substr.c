/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaida <lgaida@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 19:03:38 by lgaida            #+#    #+#             */
/*   Updated: 2025/06/03 22:27:11 by lgaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	str_len;
	size_t	substr_len;
	char	*substr;

	str_len = ft_strlen(s);
	if (start > str_len)
		return (ft_strdup(""));
	if (str_len - start < len)
	{
		substr_len = str_len - start;
	}
	else
	{
		substr_len = len;
	}
	substr = malloc(substr_len + 1);
	if (!substr)
		return (NULL);
	ft_memcpy(substr, &s[start], substr_len);
	substr[substr_len] = '\0';
	return (substr);
}
