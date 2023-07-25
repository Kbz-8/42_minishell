/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:59:21 by vvaas             #+#    #+#             */
/*   Updated: 2023/07/25 17:42:59 by vvaas            ###   ########.fr       */
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

bool	is_executable(char *path)
{
	struct stat file;
	int 		val;

	val = stat(path, &file);
	return (val == 0 && file.st_mode > 0 && file.st_mode & S_IXUSR && \
		file.st_mode & S_IXOTH && file.st_mode & S_IXGRP);
}

bool	is_executable_name(char *name)
{
	char *output;
	
	if (ft_strstr(name, "./"))
		return (0);
	if (ft_strchr(name, '/'))
		return (0);
	if (get_env_var("PATH") == NULL)
		return (0);
	output = is_exec_path(name);
	return (output != NULL);
}
char	*is_exec_path(char *name)
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
	return (NULL);
}

void	ft_execve(char *path, char **argv, char **env)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0 && execve(path, argv, env) == -1)
	{
		allfree();
		exit(get_env_data()->last_return);
	}
	else
		waitpid(pid, &get_env_data()->last_return, 0);
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
	while (args)
	{
		count += ft_strlen(args->key) + 1 + ft_strlen(args->value);
		args = args->next;
	}
	env_tab = ft_calloc(count + 1, sizeof(char *));
	args = get_env_data()->vars;
	while (args->next)
	{
		env_tab[i] = alloc((ft_strlen(args->key) + 2 + ft_strlen(args->value)) * sizeof(char));
		ft_strcpy(env_tab[i], args->key);
		ft_strcat(env_tab[i], "=");
		ft_strcat(env_tab[i], args->value);
		args = args->next;
		i++;
	}
	env_tab[i] = NULL;
	return (env_tab);
}

/*

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