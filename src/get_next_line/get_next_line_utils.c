/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaida <lgaida@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 20:57:16 by lgaida            #+#    #+#             */
/*   Updated: 2025/10/21 20:57:20 by lgaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*gnl_strdup(char *str, int *panic_button)
{
	int		str_len;
	int		i;
	char	*dest;

	if (!str)
		return (NULL);
	str_len = ft_iofc(str, '\0');
	dest = malloc(str_len + 1);
	if (!dest)
	{
		*panic_button = 1;
		return (NULL);
	}
	i = 0;
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*gnl_strjoin(char *str1, char *str2, int *panic_button)
{
	int		str1_len;
	int		str2_len;
	char	*str;

	str1_len = ft_strlen(str1);
	str2_len = ft_strlen(str2);
	str = malloc(str1_len + str2_len + 1);
	if (!str)
	{
		*panic_button = 1;
		return (NULL);
	}
	ft_memcpy(str, str1, str1_len);
	ft_memcpy(&str[str1_len], str2, str2_len);
	str[str1_len + str2_len] = '\0';
	return (str);
}

char	*gnl_substr(char *str, char start, char end, int *panic_button)
{
	char	*substr;
	int		i_start;
	int		i_end;
	int		substr_len;

	if (start)
		i_start = ft_iofc(str, start) + 1;
	else
		i_start = 0;
	if (end)
		i_end = ft_iofc(str, end) + 1;
	else
		i_end = ft_iofc(str, end);
	substr_len = i_end - i_start;
	substr = malloc(substr_len + 1);
	if (!substr)
	{
		*panic_button = 1;
		return (NULL);
	}
	ft_memcpy(substr, &str[i_start], substr_len);
	substr[substr_len] = '\0';
	return (substr);
}
