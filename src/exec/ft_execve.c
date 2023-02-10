/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:59:21 by vvaas             #+#    #+#             */
/*   Updated: 2023/02/10 20:14:39 by vvaas            ###   ########.fr       */
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
static void	ft_freesplit(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static bool	is_file(char *path)
{
	int fd;

	fd = (open(path, 00));
	if (!fd)
		return (0);
	close(fd);
	return (1);
}

static bool	is_executable(char *path)
{
	struct stat file;
	int val;

	val = stat(path, &file);
	if (val == 0 && file.st_mode > 0 && file.st_mode & S_IXUSR && file.st_mode & S_IXOTH && file.st_mode & S_IXGRP)
		return (1);
	return (0);
}

bool	is_exec_path(char *name)
{
	char **paths;
	int i;
	char *buffer;

	i = 0;
	paths = ft_split(get_env_var("PATH"), ':');
	while (paths[i])
	{
		buffer = ft_joinfree(paths[i], "/");
		buffer = ft_joinfree(buffer, name);
		if (is_file(buffer) && is_executable(buffer))
		{
			dealloc(buffer);
			ft_freesplit(paths);
			return (1);
		}
		dealloc(buffer);
		i++;
	}
	ft_freesplit(paths);
	return (0);
}

bool	is_exec(char *name)
{
	char *path;
	int offset;

	offset = 2 * (int)!(ft_strncmp(name, "./", 2) == 0);
	path = ft_joinfree(ft_strjoin((char *)get_env_var("PWD"), "/"), name + offset);
	ft_printf("%s\n", path);
	if ((offset == 2 && is_executable(path)) || is_exec_path(name))
	{
		dealloc(path);
		return (1);
	}
	return (0);
}