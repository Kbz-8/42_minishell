/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:06:31 by vvaas             #+#    #+#             */
/*   Updated: 2023/07/23 22:21:01 by vvaas            ###   ########.fr       */
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

bool	check_isdir(t_parser_info *info)
{
	struct stat file;

	stat(info->cmd.str, &file);
	if (ft_strstr(info->cmd.str, "./") && S_ISDIR(file.st_mode))
	{
		printf("minishell: %s: Is a directory\n", info->cmd.str);
		get_env_data()->last_return = 126;
		return (1);
	}
	if (!ft_strstr(info->cmd.str, "./") && (ft_strchr(info->cmd.str, '/')))
	{
		printf("minishell: %s: No such file or directory\n", info->cmd.str);
		get_env_data()->last_return = 127;
		return (1);
	}
	return (0);
}

void	command(t_parser_info *info)
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
	else if (check_isdir(info))
		return ;
	else if (is_executable_name(info->cmd.str))
		ft_execve(is_exec_path(info->cmd.str), (char **)info->args, create_env());
	else if (is_executable(info->cmd.str))
		ft_execve(info->cmd.str, (char **)info->args, create_env());
	else if (!access(info->cmd.str, F_OK))
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

bool	is_redir(t_parser_info *info)
{
	return ((info->next->link == R_OUT || info->next->link == R_OUT_ABSOLUTE) && info->next->next);
}

void	closeopen(t_parser_info *info)
{
	int fd;

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

t_parser_info	*r_out(t_parser_info *info)
{
	int save;
	t_parser_info *tmp;
	bool perror;

	perror = 0;
	tmp = info;
	while (is_redir(info))
	{
		closeopen(info);
		if (access(info->next->args[0], W_OK) != 0)
		{
			if (!perror)
				printf("minishell: %s: Permission denied\n", info->next->args[0]);	
			perror = 1;
		}	
		info = info->next;
	}
	save = dup(1);
	close(1);
	if (info->link != R_OUT_ABSOLUTE)
		open(info->next->args[0], O_CREAT | O_TRUNC | O_WRONLY, 0644);
	else
		open(info->next->args[0], O_CREAT | O_APPEND | O_WRONLY, 0644);
	if (access(info->next->args[0], W_OK) != 0)
	{
		if (!perror)
			printf("minishell: %s: Permission denied\n", info->next->args[0]);
		get_env_data()->last_return = 1;
	}
	else
		command(tmp);
	dup2(save, 1);
	close(save);
	return (info->next->next);
}

void	r_in(t_parser_info *info)
{
	int save;
	int fd;

	save = dup(0);
	close(0);
	fd = open(info->next->args[0], O_RDONLY | O_CREAT);
	if (access(info->next->args[0], R_OK) != 0)
	{
		printf("minishell: %s: Permission denied\n", info->next->args[0]);
		get_env_data()->last_return = 1;
		return ;
	}
	command(info);
	dup2(save, 0);
	close(fd);
	close(save);
}

void	c_pipe(t_parser_info *info)
{
	int saves[2];
	pid_t pid;
	static int pipes[2];

	pipe(pipes);
	saves[0] = dup(0);
	saves[1] = dup(1);
	pid = fork();
	if (pid != 0)
	{
		close(pipes[1]);
		close(saves[1]);
		waitpid(pid, 0, 0);
		dup2(pipes[0], 0);
		close(pipes[0]);
		waitpid(pid, 0, 0);
		exec_command(info->next);
		dup2(saves[0], 0);
		close(saves[0]);
		return ;
	}
	close(saves[0]);
	close(pipes[0]);	
	dup2(pipes[1], 1);
	close(pipes[1]);
	command(info);
	dup2(saves[1], 1);
	close(saves[1]);
	allfree();
	exit(0);
}

void	exec_command(t_parser_info *info)
{
	get_env_data()->listen = false;
	while (info)
	{
		if (info->link == NONE)
		{
			command(info);
			info = info->next;
		}
		else if (info->link == R_OUT || info->link == R_OUT_ABSOLUTE)
			info = r_out(info);
		else if (info->link == R_IN)
		{
			r_in(info);
			info = info->next;
		}
		else if (info && info->link == PIPE)
		{
			c_pipe(info);
			info = info->next;
			break;
		}
	}
	get_env_data()->listen = true;
}
