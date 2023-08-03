/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_out.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 21:12:12 by vvaas             #+#    #+#             */
/*   Updated: 2023/08/03 20:19:25 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nexus.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <utils.h>

bool	is_a_command(t_parser_info *info)
{
	if (ft_iswhitespace(info->cmd.str))
	{
		if (info->cmd.str == NULL)
			return (true);
		printf("minishell: %s: command not found\n", info->cmd.str);
		get_env_data()->last_return = 1;
		return (false);
	}
	if (is_executable_name(info->cmd.str))
		return (true);
	return (!check_isdir(info));
}

void	closeopen(t_parser_info *info)
{
	int	fd;

	if (info->link != R_OUT_ABSOLUTE)
	{
		fd = open(info->next->args[0], O_CREAT | O_TRUNC | O_WRONLY, 0644);
		if (fd != -1)
			close(fd);
	}
	else
	{
		fd = open(info->next->args[0], O_CREAT | O_APPEND | O_WRONLY, 0644);
		if (fd != -1)
			close(fd);
	}
}

void	ropen(int *save, t_parser_info *info, bool *perror, t_parser_info *tmp)
{
	int	fd;

	fd = 0;
	if (info->link != R_OUT_ABSOLUTE && !(*perror))
		fd = open(info->next->args[0], O_CREAT | O_TRUNC | O_WRONLY, 0644);
	else if (!(*perror))
		fd = open(info->next->args[0], O_CREAT | O_APPEND | O_WRONLY, 0644);
	if (access(info->next->args[0], W_OK) != 0)
	{
		if (!(*perror))
		{
			dup2(*save, 1);
			close(*save);
			printf("minishell: %s: Permission denied\n", info->next->args[0]);
			*perror = 1;
		}
		get_env_data()->last_return = 1;
	}
	if (fd == -1)
		return ;
	dup2(fd, 1);
	if (is_a_command(info) && !close(fd))
		command(tmp, NULL);
	dup2(*save, 1);
	close(*save);
}

t_parser_info	*next_cmd(t_parser_info *info, t_parser_info *tmp)
{
	info = info->next;
	tmp->link = info->link;
	tmp->next = info->next;
	if (tmp->link == NONE)
		return (tmp->next);
	return (tmp);
}

t_parser_info	*r_out(t_parser_info *info)
{
	int				save;
	t_parser_info	*tmp;
	bool			perror;

	perror = 0;
	tmp = info;
	while (((info->next->link == R_OUT || \
		info->next->link == R_OUT_ABSOLUTE) && info->next->next))
	{
		closeopen(info);
		if (access(info->next->args[0], W_OK) != 0)
		{
			if (!perror)
				printf("minishell: %s: Permission denied\n", \
				info->next->args[0]);
			perror = 1;
		}
		info = info->next;
	}
	save = dup(1);
	ropen(&save, info, &perror, tmp);
	return (next_cmd(info, tmp));
}
