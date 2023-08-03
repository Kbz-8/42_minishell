/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:59:21 by vvaas             #+#    #+#             */
/*   Updated: 2023/08/03 18:04:54 by vvaas            ###   ########.fr       */
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
	if (access(path, F_OK) != 0)
		return (false);
	if (access(path, X_OK) == 0)
		return (true);
	return (false);
}

bool	is_executable_name(char *name)
{
	char	*output;

	if (ft_strstr(name, "./"))
		return (0);
	if (ft_strchr(name, '/'))
		return (0);
	if (get_env_var("PATH") == NULL)
		return (0);
	if (ft_strlen(name) == 0)
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

void	ft_execve(char *path, char **argv, char **env, int *save)
{
	pid_t	pid;
	int i;

	pid = fork();
	i = 0;
	if (pid == 0)
	{
		hard_close(false);
		execve(path, argv, env);
		allfree();
		exit(get_env_data()->last_return);
	}
	else
	{
		waitpid(pid, &get_env_data()->last_return, 0);
		while (save && save[i] && save[i] != 0 && save[i] < 1024)
			close(save[i++]);
		if (WIFEXITED(get_env_data()->last_return))
			get_env_data()->last_return = \
			WEXITSTATUS(get_env_data()->last_return);
	}
}

char	**create_env(void)
{
	char			**env_tab;
	t_env_var		*args;
	unsigned int	count;

	count = 0;
	args = get_env_data()->vars;
	while (args)
	{
		count += ft_strlen(args->key) + 1 + ft_strlen(args->value);
		args = args->next;
	}
	env_tab = ft_calloc(count + 1, sizeof(char *));
	args = get_env_data()->vars;
	env_tab = create_tab(env_tab, args);
	return (env_tab);
}
