/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:06:31 by vvaas             #+#    #+#             */
/*   Updated: 2023/07/20 19:01:11 by vvaas            ###   ########.fr       */
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

t_parser_info	*r_out(t_parser_info *info, bool absolute)
{
	int save;
	t_parser_info *tmp;

	tmp = info;	
	while (is_redir(info))
	{
		if (!absolute)
			close(open(info->next->args[0], O_CREAT | O_TRUNC | O_WRONLY, 0644));
		else
			close(open(info->next->args[0], O_CREAT | O_APPEND | O_WRONLY, 0644));
		info = info->next;
		absolute = (info->link == R_OUT_ABSOLUTE);
	}
	save = dup(1);
	close(1);
	if (!absolute)
		open(info->next->args[0], O_CREAT | O_TRUNC | O_WRONLY, 0644);
	else
		open(info->next->args[0], O_CREAT | O_APPEND | O_WRONLY, 0644);
	command(tmp);
	dup2(save, 1);
	close(save);
	while (info->link == R_OUT | info->link == R_OUT_ABSOLUTE)
		info = info->next;
	return (info->next);
}

void	r_in(t_parser_info *info)
{
	int save;
	int fd;

	save = dup(0);
	close(0);
	fd = open(info->next->args[0], O_RDONLY | O_CREAT);
	command(info);
	dup2(save, 0);
	close(fd);
	close(save);
}

int	count_pipe(t_parser_info *info)
{
	int i;

	i = 1;
	while(info->link == PIPE)
	{
		i++;
		info = info->next;
	}
	return (i);
		
}

/*void	c_pipe(t_parser_info *info)
{
	size_t	n_pipe;
	int **pipes;
	int i;

	i = 0;
	n_pipe = count_pipe(info);
	pipes = (int **)alloc(sizeof(int *) * n_pipe - 1);
	while(i < n_pipe - 1)
	{
		pipes[i] = (int *)alloc(sizeof(int), 2);
		if (pipe(pipes[i] == -1)
		{
			printf("pipe error\n");
			get_env_var()->last_return = 127;
			exit(127);
		}
	}
}*/

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
		close(saves[1]);
		waitpid(pid, 0, 0);
		close(0);
		dup(pipes[0]);
		waitpid(pid, 0, 0);
		exec_command(info->next);
		close(0);
		dup(saves[0]);
		close(pipes[0]);
		close(saves[0]);
		return ;
	}
	close(saves[0]);
	close(pipes[0]);
	close(1);
	dup(pipes[1]);
	command(info);
	close(1);
	dup(saves[1]);
	close(pipes[1]);
	close(saves[1]);
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
			info = r_out(info, (info->link == R_OUT_ABSOLUTE));
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
