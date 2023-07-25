/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_in.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 21:08:40 by vvaas             #+#    #+#             */
/*   Updated: 2023/07/25 21:45:19 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nexus.h>
#include <libft.h>
#include <fcntl.h>
#include <unistd.h>
#include <utils.h>
#include <memory.h>

t_parser_info	*r_in(t_parser_info *info)
{
	int		save;
	int		fd;
	char	*buffer;

	if (r_in_error(info))
		return (jump_next_pipe(info));
	save = dup(0);
	close(0);
	buffer = (char *)info->next->args[0];
	fd = open(info->next->args[0], O_RDONLY | O_CREAT);
	exec_command(jump_next(info));
	if (ft_strcmp(buffer, "/tmp/HEREDOC") == 0)
		unlink("/tmp/HEREDOC");
	dup2(save, 0);
	close(save);
	return (NULL);
}

t_parser_info	*r_doc(t_parser_info *info)
{
	int	fd;

	fd = open("/tmp/HEREDOC", O_CREAT | O_TRUNC | O_WRONLY, 0644);
	write(fd, info->next->args[0], ft_strlen(info->next->args[0]));
	close(fd);
	dealloc((char *)info->next->args[0]);
	info->next->args[0] = ft_strdup("/tmp/HEREDOC");
	info->link = R_IN;
	return (info);
}
