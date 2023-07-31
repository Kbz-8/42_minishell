/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:06:31 by vvaas             #+#    #+#             */
/*   Updated: 2023/07/31 19:37:12 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nexus.h>
#include <memory.h>
#include <builtin.h>
#include <stdbool.h>
#include <utils.h>
#include <libft.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <utils.h>

bool	check_isdir(t_parser_info *info)
{
	struct stat	file;

	if (stat(info->cmd.str, &file) == -1)
	{
		printf("minishell: %s: No such file or directory\n", info->cmd.str);
		get_env_data()->last_return = 127;
		return (1);
	}
	if (ft_strstr(info->cmd.str, "./") && S_ISDIR(file.st_mode))
	{
		printf("minishell: %s: Is a directory\n", info->cmd.str);
		get_env_data()->last_return = 126;
		return (1);
	}
	if (ft_strstr(info->cmd.str, "./") && access(info->cmd.str, X_OK) != 0)
	{
		printf("minishell: %s: Permission denied\n", info->cmd.str);
		get_env_data()->last_return = 126;
		return (1);
	}
	return (0);
}

bool	is_dot(t_parser_info *info)
{
	return (ft_strcmp(info->cmd.str, ".") == 0 || \
	ft_strcmp(info->cmd.str, "..") == 0);
}

void	check_input(t_parser_info *info, int *save)
{
	if (is_dot(info))
		return ;
	if (is_executable_name(info->cmd.str))
		ft_execve(is_exec_path(info->cmd.str), \
		(char **)info->args, create_env(), save);
	else if (check_isdir(info))
		return ;
	else if (is_executable(info->cmd.str))
		ft_execve(info->cmd.str, (char **)info->args, create_env(), save);
	else if (access(info->cmd.str, F_OK))
	{
		printf("minishell: %s: Permission denied\n", info->args[0]);
		get_env_data()->last_return = 126;
	}
	else
	{
		printf("%s: command not found\n", info->cmd.str);
		get_env_data()->last_return = 127;
	}
}

void	command(t_parser_info *info, int *save)
{
	if (!info || info->cmd.str == NULL)
		return ;
	if (info->cmd.builtin < 8 && info->cmd.builtin > 0)
	{
		if (info->cmd.builtin == ECHO)
			ft_echo(info);
		if (info->cmd.builtin == EXIT)
			ft_exit(info);
		else if (info->cmd.builtin == PWD)
			ft_pwd();
		else if (info->cmd.builtin == CD)
			ft_cd(info);
		else if (info->cmd.builtin == ENV)
			ft_env(info);
		else if (info->cmd.builtin == EXPORT)
			ft_export(info);
		else if (info->cmd.builtin == UNSET)
			ft_unset(info);
	}
	else
		check_input(info, save);
}

void	exec_command(t_parser_info *info, int fd)
{
	get_env_data()->listen = false;
	while (info)
	{
		if (info->link == NONE)
		{
			command(info, &fd);
			info = info->next;
		}
		else if (info->link == HERE_DOC)
			info = r_doc(info);
		else if (info && (info->link == R_OUT || info->link == R_OUT_ABSOLUTE))
			info = r_out(info);
		else if (info && info->link == R_IN)
			info = r_in(info, 0);
		else if (info && info->link == PIPE)
		{
			c_pipe(info, fd);
			info = info->next;
			break ;
		}
	}
	get_env_data()->listen = true;
}
