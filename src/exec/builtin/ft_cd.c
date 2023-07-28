/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 08:32:33 by vvaas             #+#    #+#             */
/*   Updated: 2023/07/28 21:07:05 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nexus.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errors.h>
#include <libft.h>
#include <utils.h>

bool	is_nor_dir_or_file(char *info)
{
	struct stat	file;

	if (!info)
		return (0);
	if (stat(info, &file))
	{
		ft_printf("minishell: cd: %s: No such file or directory\n", info);
		get_env_data()->last_return = 1;
		return (1);
	}
	return (0);
}

bool	is_dir(char *info)
{
	struct stat	file;

	if (stat(info, &file))
		return (0);
	if (!S_ISDIR(file.st_mode))
	{
		ft_printf("minishell: cd: %s: Not a directory\n", info);
		get_env_data()->last_return = 1;
	}
	return (S_ISDIR(file.st_mode));
}

bool	have_access(char *info)
{
	if (access(info, R_OK | X_OK) == 0)
		return (1);
	ft_printf("minishell: cd: %s: Permission denied\n", info);
	get_env_data()->last_return = 1;
	return (0);
}

bool	check_validity(char *info)
{
	if (is_nor_dir_or_file(info))
		return (0);
	if (!is_dir(info))
		return (0);
	if (!have_access(info))
		return (0);
	return (1);
}

int	ft_cd(t_parser_info *info)
{
	if (!info->args[1])
	{
		if (!get_env_var("HOME"))
		{
			ft_printf("minishell: cd: HOME not set\n");
			get_env_data()->last_return = 1;
			return (0);
		}
		ft_changedir();
		return (1);
	}
	else if (info->args[2])
	{
		report(ERROR, E_TOO_MANY_ARGS);
		get_env_data()->last_return = 1;
		return (1);
	}
	return (ft_setcwd(info));
}
