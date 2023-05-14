/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:59:21 by vvaas             #+#    #+#             */
/*   Updated: 2023/05/14 14:08:12 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <fcntl.h>
#include <unistd.h>
#include <nexus.h>
#include <libft.h>
#include <memory.h>
#include <utils.h>
#include <sys/stat.h>
#include <builtin.h>
#include <signal.h>
#include <stdio.h>
#include <readline/readline.h>
#include <sys/types.h>
#include <sys/wait.h>

static bool	is_executable(char *path)
{
	struct stat file;
	int 		val;

	val = stat(path, &file);
	return (val == 0 && file.st_mode > 0 && file.st_mode & S_IXUSR && \
		file.st_mode & S_IXOTH && file.st_mode & S_IXGRP);
}

bool	is_exec_path(char *name)
{
	char	**paths;
	int		i;
	char	*buffer;

	i = 0;
	paths = ft_split(get_env_var("PATH"), ':');
	while (paths[i])
	{
		buffer = ft_strjoin(paths[i], "/");
		buffer = ft_joinfree(buffer, name);
		if (is_executable(buffer))
		{
			ft_free(buffer);
			ft_freesplit(paths);
			return (1);
		}
		ft_free(buffer);
		i++;
	}
	ft_freesplit(paths);
	return (0);
}

char	*get_exec_path(char *name)
{
	char	**paths;
	int		i;
	char	*buffer;

	i = 0;
	paths = ft_split(get_env_var("PATH"), ':');
	while (paths[i])
	{
		buffer = ft_strjoin(paths[i], "/");
		buffer = ft_joinfree(buffer, name);
		if (is_executable(buffer))
		{
			ft_freesplit(paths);
			return (buffer);
		}
		ft_free(buffer);
		i++;
	}
	ft_freesplit(paths);
	return (0);
}

char	**do_tab(char *input)
{
	char	**tab;

	tab = ft_calloc(2, sizeof(char *));
	tab[0] = ft_calloc(ft_strlen(ft_strrchr(input, '/') + 1), sizeof(char));
	tab[0] = ft_strrchr(input, '/') + 1;
	tab[1] = NULL;
	return (tab);
}

void	ft_exec(char *input)
{
	pid_t	pid;

	if (is_executable(input))
	{
		kill(getpid(), SIGUSR1);
		pid = fork();
		if (pid == 0)
		{
			execve(input, do_tab(input), NULL);
			kill(getpid(), SIGTERM);
		}
		else
		{
			waitpid(pid, 0, 0);
			kill(getpid(), SIGUSR1);
			printf("\n");
		}
	}
	return;
}

int	is_exec(char *input)
{
	if (is_executable(input))
		return (1);
	if (is_exec_path(input))
		return (2);
	return (0);
}
