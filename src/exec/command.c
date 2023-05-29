/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:06:31 by vvaas             #+#    #+#             */
/*   Updated: 2023/05/28 16:34:54 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nexus.h>
#include <memory.h>
#include <builtin.h>
#include <stdbool.h>
#include <utils.h>

void	command(t_parser_info *info)
{
	if (info->cmd.builtin < 8)
	{
		if (info->cmd.builtin == ECHO)
			ft_echo(info);
		if (info->cmd.builtin == EXIT)
			ft_exit(info);
		else if (info->cmd.builtin == PWD)
			ft_pwd(info);
		else if (info->cmd.builtin == CD)
			ft_cd(info);
	}
}

bool	is_command(char *input)
{
	if (is_exec(input) > 0)
		return (1);
	return (0);
}
