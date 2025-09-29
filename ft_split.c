/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaida <lgaida@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 19:01:26 by lgaida            #+#    #+#             */
/*   Updated: 2025/06/03 22:24:36 by lgaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	count_entries(char const *s, char c)
{
	size_t	i;
	size_t	entries;
	int		in_entry;

	i = 0;
	entries = 0;
	in_entry = 0;
	while (s[i])
	{
		if (s[i] != c && !in_entry)
		{
			entries++;
			in_entry = 1;
		}
		else if (s[i] == c)
			in_entry = 0;
		i++;
	}
	return (entries);
}

static size_t	entry_len(char const *s, char c, size_t start)
{
	size_t	len;

	len = 0;
	while (s[start + len] && s[start + len] != c)
		len++;
	return (len);
}

static int	build_array(char **array, char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			array[j] = malloc(entry_len(s, c, i) + 1);
			if (!array[j])
			{
				while (j-- > 0)
					free(array[j]);
				return (0);
			}
			i = i + entry_len(s, c, i);
			j++;
		}
		else
			i++;
	}
	array[j] = NULL;
	return (1);
}

static void	fill_array(char **array, char const *s, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			k = 0;
			while (s[i] && s[i] != c)
			{
				array[j][k] = s[i];
				i++;
				k++;
			}
			array[j][k] = '\0';
			j++;
		}
		else
			i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	entries;

	entries = count_entries(s, c);
	array = malloc(sizeof(char *) * (entries + 1));
	if (!array)
		return (NULL);
	if (!build_array(array, s, c))
	{
		free(array);
		return (NULL);
	}
	fill_array(array, s, c);
	return (array);
}
