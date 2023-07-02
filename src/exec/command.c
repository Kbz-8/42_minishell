/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:06:31 by vvaas             #+#    #+#             */
/*   Updated: 2023/07/02 23:21:21 by vvaas            ###   ########.fr       */
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

void	command(t_parser_info *info)
{
	if (!info)
		return ;
	if (info->cmd.builtin < 8 && info->cmd.builtin > 0)
	{
		if (info->cmd.builtin == ECHO)
			ft_echo(info);
		if (info->cmd.builtin == EXIT)
			ft_exit(info);
		else if (info->cmd.builtin == PWD)
			ft_pwd(info);
		else if (info->cmd.builtin == CD)
			ft_cd(info);
		else if (info->cmd.builtin == ENV)
			ft_env(info);
		else if (info->cmd.builtin == EXPORT)
			ft_export(info);
		else if (info->cmd.builtin == UNSET)
			ft_unset(info);
	}
	else if (is_executable_name(info->cmd.str))
		ft_execve(is_exec_path(info->cmd.str), (char **)info->args, create_env());
	else if (is_environment(info->cmd.str))
		add_env(info->cmd.str);
	else if (is_executable(info->cmd.str))
		ft_execve(info->cmd.str, (char **)info->args, create_env());
}

void	r_out_absolute(t_parser_info *info)
{
	int save;

	save = dup(1);
	close(1);
	open(info->next->args[0], O_CREAT | O_APPEND | O_WRONLY, 0644);
	command(info);
	dup2(save, 1);
}

void	r_out(t_parser_info *info)
{
	int save;

	save = dup(1);
	close(1);
	open(info->next->args[0], O_CREAT | O_TRUNC | O_WRONLY, 0644);
	command(info);
	dup2(save, 1);
}

void	r_in(t_parser_info *info)
{
	int save;

	save = dup(0);
	close(0);
	open(info->next->args[0], O_CREAT | O_RDONLY);
	command(info);
	dup2(save, 0);
}

void	c_pipe(t_parser_info *info)
{
	int saves[2];
	pid_t pid;
	int pipes[2];

	pipe(pipes);
	saves[0] = dup(0);
	saves[1] = dup(1);
	pid = fork();
	if (pid != 0)
	{
		close(pipes[1]);
		waitpid(pid, 0, 0);
		close(0);
		dup(pipes[0]);
		exec_command(info->next);
		dup2(saves[0], 0);
		return ;
	}
	close(pipes[0]);
	close(1);
	dup(pipes[1]);
	command(info);
	dup2(saves[1], 1);
	exit(0);
}

void	exec_command(t_parser_info *info)
{
	while (info)
	{
		get_env_data()->listen = false;
		if (info->link == NONE)
			command(info);
		if (info->link == R_OUT_ABSOLUTE)
			r_out_absolute(info);
		else if (info->link == R_OUT)
			r_out(info);
		else if (info->link == R_IN)
			r_in(info);
		else if (info && info->link == PIPE)
		{
			c_pipe(info);
			break;
		}
		info = info->next;
	}
	get_env_data()->listen = true;
}