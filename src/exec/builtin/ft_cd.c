/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 08:32:33 by vvaas             #+#    #+#             */
/*   Updated: 2023/07/13 17:01:59 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nexus.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errors.h>
#include <libft.h>

bool	is_nor_dir_or_file(t_parser_info *info)
{
	struct stat file;

	if (!info->args[1])
		return (0);
	if (stat(info->args[1], &file))
	{
		ft_printf("minishell: cd: %s: No such file or directory\n", info->args[1]);
		get_env_data()->last_return = 1;
		return (1);
	}
	return (0);
}

bool	is_dir(t_parser_info *info)
{
	struct stat file;

	if (stat(info->args[1], &file))
		return (0);
	if (!S_ISDIR(file.st_mode))
	{
		ft_printf("minishell: cd: %s: Not a directory\n", info->args[1]);
		get_env_data()->last_return = 1;
	}
	return S_ISDIR(file.st_mode);
}

bool	have_access(t_parser_info *info)
{
	if (access(info->args[1], R_OK | X_OK) == 0)
		return (1);
	ft_printf("minishell: cd: %s: Permission denied\n", info->args[1]);
	get_env_data()->last_return = 1;
	return (0);
}

int	ft_cd(t_parser_info *info)
{
	void *buffer;

	if (!info->args[1])
		chdir(get_env_var("HOME"));
	if (info->args[2])
	{
		report(ERROR, E_TOO_MANY_ARGS);
		get_env_data()->last_return = 1;
		return (1);
	}
	else if (is_nor_dir_or_file(info))
		return (1);
	else if (!is_dir(info))
		return (1);
	if (!have_access(info))
		return (1);
	chdir(info->args[1]);
	buffer = getcwd(NULL, 0);
	modify_env_var("PWD", "PWD", buffer);
	free(buffer);
	return (0);
}