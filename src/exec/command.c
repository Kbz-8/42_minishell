/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:06:31 by vvaas             #+#    #+#             */
/*   Updated: 2023/07/25 00:12:51 by vvaas            ###   ########.fr       */
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
	else if (is_executable_name(info->cmd.str))
		ft_execve(is_exec_path(info->cmd.str), (char **)info->args, create_env());
	else if (check_isdir(info))
		return ;
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
	int	link;
	int fd;

	fd = -1;
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
	if (info->link != R_OUT_ABSOLUTE && !perror)
		fd = open(info->next->args[0], O_CREAT | O_TRUNC | O_WRONLY, 0644);
	else if (!perror)
		fd = open(info->next->args[0], O_CREAT | O_APPEND | O_WRONLY, 0644);
	if (access(info->next->args[0], W_OK) != 0)
	{
		if (!perror)
		{
			dup2(save, 1);
			close(save);
			printf("minishell: %s: Permission denied\n", info->next->args[0]);
			perror = 1;
		}
		get_env_data()->last_return = 1;
	}
	if (fd != -1)
	{
		dup2(fd, 1);
		command(tmp);
		dup2(save, 1);
		close(save);
	}
	info = info->next;
	link = info->link;
	tmp->link = link; // link de zelda loul 	
	tmp->next = info->next;
	if (tmp->link == NONE)
		return (tmp->next);
	return (tmp);
}

t_parser_info *jump_next_pipe(t_parser_info *info)
{
	while (info->next && info->link != PIPE)
		info = info->next;
	if (info->next == NULL)
		return (NULL);
	return (info);
}

bool	is_a_dir(char *path)
{
	struct stat file;

	stat(path, &file);
	if (S_ISDIR(file.st_mode))
	{
		printf("minishell: %s: Is a directory\n", path);
		get_env_data()->last_return = 127;
		return (1);
	}
	return (0);
}

t_parser_info *jump_next(t_parser_info *info)
{
	t_parser_info *tmp;

	tmp = info;
	info = info->next;
	tmp->link = info->link;
	tmp->next = info->next;
	return (tmp);
}

bool	r_in_error(t_parser_info *info)
{
	struct stat file;

	if (stat(info->next->args[0], &file) == -1)
	{
		printf("minishell: %s: No such file or directory\n", info->next->args[0]);
		get_env_data()->last_return = 127;
		return (1);
	}
	if (is_a_dir((char *)info->next->args[0]))
		return (1);
	if (access(info->next->args[0], R_OK) != 0)
	{
		printf("minishell: %s: Permission denied\n", info->next->args[0]);
		get_env_data()->last_return = 1;
		return (1);
	}
	return (0);
}

t_parser_info *r_in(t_parser_info *info)
{
	int save;
	int fd;

	if (r_in_error(info))
		return (jump_next_pipe(info));
	save = dup(0);
	close(0);
	fd = open(info->next->args[0], O_RDONLY | O_CREAT);
	info = jump_next(info);
	exec_command(info);
	dup2(save, 0);
	close(save);
	return (NULL);
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
	printf("MY PID IS : %d, save[0] = %d, save[1] = %d\n", pid, saves[0], saves[1]);
	if (pid != 0)
	{
		close(pipes[1]);
		close(saves[1]);
		waitpid(pid, 0, 0);
		dup2(pipes[0], 0);
		close(pipes[0]);
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
		else if (info && (info->link == R_OUT || info->link == R_OUT_ABSOLUTE))
			info = r_out(info);
		else if (info && info->link == R_IN)
			info = r_in(info);
		else if (info && info->link == PIPE)
		{
			c_pipe(info);
			info = info->next;
			break;
		}
	}
	get_env_data()->listen = true;
}
