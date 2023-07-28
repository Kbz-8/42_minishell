/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_in.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 21:08:40 by vvaas             #+#    #+#             */
/*   Updated: 2023/07/28 19:34:00 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nexus.h>
#include <libft.h>
#include <fcntl.h>
#include <unistd.h>
#include <utils.h>
#include <builtin.h>
#include <memory.h>

t_parser_info	*r_in(t_parser_info *info, bool heredoc)
{
	int		save;
	char	*buffer;

	if (r_in_error(info))
		return (jump_next_pipe(info));
	save = dup(0);
	close(0);
	buffer = (char *)info->next->args[0];
	open(info->next->args[0], O_RDONLY | O_CREAT);
	jump_next(info);
	if (info->link == NONE)
		exec_command(info, 0);
	else
		exec_command(info, save);
	if (heredoc)
		unlink(buffer);
	dup2(save, 0);
	close(save);
	return (NULL);
}

char	*generate_tmp(void)
{
	int		i;
	char	*buffer;

	i = 0;
	buffer = ft_strjoin("/tmp/HEREDOC", ft_itoa(i));
	while (access(buffer, F_OK) == 0)
	{
		dealloc(buffer);
		i++;
		buffer = ft_strjoin("/tmp/HEREDOC", ft_itoa(i));
	}
	return (buffer);
}

t_parser_info	*r_doc(t_parser_info *info)
{
	int		fd;
	char	*buffer;

	buffer = generate_tmp();
	fd = open(buffer, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (fd != -1)
	{
		write(fd, info->next->args[0], ft_strlen(info->next->args[0]));
		close(fd);
	}
	dealloc((char *)info->next->args[0]);
	info->next->args[0] = ft_strdup(buffer);
	info->link = R_IN;
	r_in(info, 1);
	return (NULL);
}
