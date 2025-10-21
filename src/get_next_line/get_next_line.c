/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaida <lgaida@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 20:57:07 by lgaida            #+#    #+#             */
/*   Updated: 2025/10/21 20:57:09 by lgaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*line;
	int			panic_button;

	panic_button = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!stash[fd])
		stash[fd] = gnl_strdup("", &panic_button);
	read_from_fd(fd, &(stash[fd]), &panic_button);
	extract_line(&(stash[fd]), &line, &panic_button);
	if (panic_button == 1 || !line || !line[0])
	{
		free(stash[fd]);
		free(line);
		return (NULL);
	}
	else
		return (line);
}

void	read_from_fd(int fd, char **stash, int *panic_button)
{
	char	*buffer;
	int		bytes_read;
	char	*temp;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		*panic_button = 1;
		return ;
	}
	while (ft_iofc(*stash, '\n') == -1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 1)
		{
			if (bytes_read < 0)
				*panic_button = 1;
			break ;
		}
		buffer[bytes_read] = '\0';
		temp = gnl_strjoin(*stash, buffer, panic_button);
		free (*stash);
		*stash = temp;
	}
	free(buffer);
}

void	extract_line(char **stash, char **line, int *panic_button)
{
	char	*temp;

	if (ft_iofc(*stash, '\n') >= 0)
	{
		*line = gnl_substr(*stash, 0, '\n', panic_button);
		temp = gnl_substr(*stash, '\n', '\0', panic_button);
		free(*stash);
		*stash = temp;
	}
	else
	{
		*line = gnl_strdup(*stash, panic_button);
		free(*stash);
		*stash = gnl_strdup("", panic_button);
	}
}
