/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-furi <mm-furi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:59:43 by mm-furi           #+#    #+#             */
/*   Updated: 2024/10/09 17:57:27 by mm-furi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t i, size_t c)
{
	void			*str;
	size_t			total_size;
	size_t			j;
	unsigned char	*ptr;

	total_size = i * c;
	if (i != 0 && c > SIZE_MAX / i)
		return (NULL);
	str = malloc(total_size);
	if (str == NULL)
		return (NULL);
	ptr = (unsigned char *)str;
	j = 0;
	while (j < total_size)
	{
		ptr[j] = 0;
		j++;
	}
	return (str);
}

int	ft_strchr(const char *str, int c)
{
	int		i;

	if (!str)
		return (-1);
	i = 0;
	while (str && str[i])
	{
		if (str[i] == (char)c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strndup(char *src, size_t n)
{
	size_t	i;
	char	*lol;

	if (!src)
		return (NULL);
	lol = (char *)malloc(n + 1);
	if (lol == NULL)
		return (NULL);
	i = 0;
	while (i < n && src[i] != '\0')
	{
		lol[i] = src[i];
		i++;
	}
	lol[i] = '\0';
	return (lol);
}

char	*ft_strnjoin(char const *s1, char const *s2, size_t n)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s2 || s2[0] == '\0')
		return (NULL);
	str = (char *)malloc(ft_strlen(s1) + n + 1);
	if (!str)
		return (NULL);
	if (s1 != NULL)
	{
		while (s1[i] != '\0')
		{
			str[i] = s1[i];
			i++;
		}
	}
	while (s2[j] != '\0' && j < n)
		str[i++] = s2[j++];
	str[i] = '\0';
	if (s1)
		ft_free((char **)&s1);
	return (str);
}

int	read_and_append(int fd, char **next_line)
{
	char	buff[BUFFER_SIZE + 1];
	int		bytes;

	bytes = read(fd, buff, BUFFER_SIZE);
	if (bytes <= 0)
	{
		if (bytes == -1)
			return (-1);
		return (0);
	}
	buff[bytes] = '\0';
	*next_line = ft_strnjoin(*next_line, buff, bytes);
	if (*next_line)
		return (1);
	return (-1);
}
