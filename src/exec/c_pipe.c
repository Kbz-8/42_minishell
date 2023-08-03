/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_pipe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 21:46:24 by vvaas             #+#    #+#             */
/*   Updated: 2023/08/03 17:51:18 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nexus.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <utils.h>
#include <memory.h>
#include <stdlib.h>
#include <builtin.h>
#include <stdio.h>
#include <signal.h>

void	last_pipe_cmd(t_parser_info *info, int save)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		exec_command(info, save);
		dup2(save, 0);
		close(save);
		allfree();
		hard_close(false);
		exit(get_env_data()->last_return);
	}
	else
		waitpid(pid, &get_env_data()->last_return, 0);
}

void	continue_to_next_cmd(t_parser_info *info, int *saves, int *p, int pid)
{
	close(p[1]);
	close(saves[1]);
	dup2(p[0], 0);
	close(p[0]);
	if (jump_next_pipe(info->next) == NULL)
		last_pipe_cmd(info->next, saves[0]);
	else
		exec_command(info->next, saves[0]);
	dup2(saves[0], 0);
	close(saves[0]);
	waitpid(pid, 0, 0);
	return ;
}

void	exec_pipe_cmd(int *t_save, int *saves, int *pipes, t_parser_info *info)
{
	close(saves[0]);
	close(pipes[0]);
	dup2(pipes[1], 1);
	close(pipes[1]);
	command(info, t_save);
	dup2(saves[1], 1);
	close(saves[1]);
	hard_close(false);
	allfree();
	exit(0);
}

void	c_pipe(t_parser_info *info, int fd)
{
	int			saves[2];
	pid_t		pid;
	int			pipes[2];
	static int	t_save[1024] = {0};

	pipe(pipes);
	saves[0] = dup(0);
	saves[1] = dup(1);
	if (fd != -1)
		append_value(t_save, fd);
	pid = fork();
	if (pid != 0)
	{
		append_value(t_save, saves[0]);
		continue_to_next_cmd(info, saves, pipes, pid);
		return ;
	}
	append_value(t_save, saves[1]);
	exec_pipe_cmd(t_save, saves, pipes, info);
}
