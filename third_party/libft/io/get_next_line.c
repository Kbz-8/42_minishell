/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:34:11 by maldavid          #+#    #+#             */
/*   Updated: 2023/05/14 11:03:09 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

#ifndef BUFFER_SIZE

# define BUFFER_SIZE 1
#endif

char	*ft_strnjoin(char const *s1, char const *s2, int n);

static void	ft_save(char **save, char *buf)
{
	unsigned int	size;

	if (BUFFER_SIZE < 2 || !buf || *buf == 0)
		return ;
	size = ft_strlen(buf);
	ft_free(*save);
	*save = (char *)ft_malloc(size + 1);
	if (*save == NULL)
		return ;
	ft_memset(*save, 0, size + 1);
	ft_strcpy(*save, buf);
}

static char	*process_line(char *line, char *ptr, char *buffer, char **save)
{
	char	*buf;

	line = ft_strnjoin(line, buffer, ptr - buffer + 1);
	buf = ft_strnjoin(NULL, ptr, -1);
	if (*save != buffer)
		ft_free(buffer);
	ft_save(save, buf + 1);
	ft_free(buf);
	return (line);
}

static void	ft_save_init(char **save, char **line)
{
	*line = NULL;
	if (*save && **save)
		*line = ft_strnjoin(NULL, *save, -1);
	ft_free(*save);
	*save = NULL;
}

static char	*read_line(int fd, char **save)
{
	char	*line;
	char	*ptr;
	char	*buffer;

	if (*save && **save)
	{
		line = NULL;
		ptr = ft_strchr(*save, '\n');
		if (ptr && ft_strlen(ptr) > 1)
			return (process_line(line, ptr, *save, save));
	}
	buffer = (char *)ft_malloc(BUFFER_SIZE + 1);
	ft_memset(buffer, 0, BUFFER_SIZE + 1);
	ft_save_init(save, &line);
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		ptr = ft_strchr(buffer, '\n');
		if (ptr)
			return (process_line(line, ptr, buffer, save));
		line = ft_strnjoin(line, buffer, -1);
		ft_memset(buffer, 0, ft_strlen(buffer));
	}
	ft_free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*save = NULL;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	return (read_line(fd, &save));
}
