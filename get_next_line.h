/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-furi <mm-furi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:05:06 by mm-furi           #+#    #+#             */
/*   Updated: 2024/10/09 17:55:08 by mm-furi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_fd_buffer
{
	int					fd;
	char				*buffer;
	struct s_fd_buffer	*next;
}t_fd_buffer;

int		ft_strlen(const char *s);
char	*ft_strndup(char *src, size_t n);
void	ft_free(char **s);
void	*ft_calloc(size_t i, size_t c);
int		ft_strchr(const char *str, int c);
char	*ft_strnjoin(char const *s1, char const *s2, size_t n);
char	*ft_update_nl(char **next_line, int position);
char	*ft_output(char **next_line, int position, int bytes);
char	*get_next_line(int fd);
int		read_and_append(int fd, char **next_line);
#endif