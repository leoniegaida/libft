/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaida <lgaida@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 18:58:41 by lgaida            #+#    #+#             */
/*   Updated: 2025/06/03 18:05:36 by lgaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	mem_size;

	if (nmemb == 0 || size == 0)
	{
		ptr = malloc(0);
		return (ptr);
	}
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	mem_size = nmemb * size;
	ptr = malloc(mem_size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, mem_size);
	return (ptr);
}
