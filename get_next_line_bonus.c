/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-furi <mm-furi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:50:16 by mm-furi           #+#    #+#             */
/*   Updated: 2024/10/10 17:51:49 by mm-furi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free(char **s)
{
	free(*s);
	*s = NULL;
}

int	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_update_nl(char **next_line, int position)
{
	char	*tmp;
	int		len;

	len = ft_strlen(*next_line) - position;
	tmp = ft_strndup(*next_line + position, len);
	ft_free(next_line);
	*next_line = tmp;
	return (*next_line);
}

char	*ft_output(char **next_line, int position, int bytes)
{
	char	*line;

	if (!*next_line)
		return (NULL);
	if (bytes == 0 || bytes == -1)
	{
		if (position == -1)
			position = ft_strlen(*next_line);
		line = ft_strndup(*next_line, position);
		ft_free(next_line);
		return (line);
	}
	if (position == -1)
		position = (int)ft_strlen(*next_line);
	else
		position++;
	line = ft_strndup(*next_line, position);
	if (position == (int)ft_strlen(*next_line))
		ft_free(next_line);
	else
		*next_line = ft_update_nl(next_line, position);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*next_line[OPEN_MAX];
	int			position;
	int			status;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 10240)
		return (NULL);
	position = ft_strchr(next_line[fd], '\n');
	while (position == -1)
	{
		status = read_and_append(fd, &next_line[fd]);
		if (status == -1)
		{
			ft_free(&next_line[fd]);
			return (NULL);
		}
		if (status == 0)
			break ;
		position = ft_strchr(next_line[fd], '\n');
	}
	return (ft_output(&next_line[fd], position, status));
}
