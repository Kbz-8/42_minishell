/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:59:21 by vvaas             #+#    #+#             */
/*   Updated: 2023/02/10 19:17:01 by vvaas            ###   ########.fr       */
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
	if (val == 0 && file.st_mode > 0 && file.st_mode & S_IXUSR)
	{
		ft_printf("%s\n", path);
		return (1);
	}
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
			free(buffer);
			ft_freesplit(paths);
			return (1);
		}
		free(buffer);
		i++;
	}
	ft_freesplit(paths);
	return (0);
}

bool	is_exec(char *name)
{
	char *path;
	int offset;

	offset = 0;
	if (ft_strncmp(name, "./", 2) == 0)
		offset = 2;
	path = ft_strjoin((char *)get_env_var("PWD"), "/");
	path = ft_joinfree(path, name + offset);
	if (offset == 2 && is_executable(path))
	{
		ft_printf("%s\n", path);
		free(path);
		return (1);
	}
	free(path);
	if (is_exec_path(name))
		return (1);
	return (0);
}