#include "libft.h"

size_t	ft_count_entries(char const *s, char c)
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