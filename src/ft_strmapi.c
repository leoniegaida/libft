/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaida <lgaida@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 19:02:55 by lgaida            #+#    #+#             */
/*   Updated: 2025/06/03 17:41:04 by lgaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str_mod;
	unsigned int	i;

	str_mod = malloc(ft_strlen(s) + 1);
	if (!str_mod)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str_mod[i] = f(i, s[i]);
		i++;
	}
	str_mod[i] = '\0';
	return (str_mod);
}
