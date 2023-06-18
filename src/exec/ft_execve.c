/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:59:21 by vvaas             #+#    #+#             */
/*   Updated: 2023/06/18 17:47:47 by vvaas            ###   ########.fr       */
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

char	*create_input(t_parser_info *info)
{
	char *input;
	unsigned int i;
	unsigned int count;

	i = 1;
	count = 0;
	count += ft_strlen(info->cmd.str);
	while (info->args[i])
	{
		count += ft_strlen(info->args[i]) + 1;
		i++;
	}
	input = ft_calloc(count + 1, sizeof(char));
	ft_strcpy(input, info->cmd.str);
	i = 1;
	while (info->args[i])
	{
		ft_strcat(input, " ");
		ft_strcat(input, info->args[i++]);
	}
	return (input);
}

char	**create_env(void)
{
	char **env_tab;
	t_env_var *args;
	unsigned int i;
	unsigned int count;

	i = 0;
	count = 0;
	args = get_env_data()->vars;
	while (args->next)
	{
		count += ft_strlen(args->key) + 1 + ft_strlen(args->value);
		args = args->next;
	}
	count += ft_strlen(args->key) + 1 + ft_strlen(args->value);
	env_tab = ft_calloc(count, sizeof(char *));
	args = get_env_data()->vars;
	while (args->next)
	{
		env_tab[i] = ft_calloc(ft_strlen(args->key) + 1 + ft_strlen(args->value), sizeof(char));
		ft_strcpy(env_tab[i], args->key);
		ft_strcat(env_tab[i], "=");
		ft_strcat(env_tab[i], args->value);
		args = args->next;
		i++;
	}
	return (env_tab);
}

/*
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

char	*create_input(t_parser_info *info)
{
	char *input;
	unsigned int i;
	unsigned int count;

	i = 0;
	count = 0;
	count += ft_strlen(info->cmd.str);
	while (info->args[i])
	{
		count += ft_strlen(info->args[i]);
		i++;
	}
	input = ft_calloc(count + 1, sizeof(char));
	ft_strcpy(input, info->cmd.str);
	i = 0;
	while (info->args[i])
		ft_strcpy(input, info->args[i++]);
	return (input);
}

void	ft_exec(t_parser_info *info)
{
	pid_t	pid;

	if (is_executable(info->cmd.str))
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
*/