/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:06:31 by vvaas             #+#    #+#             */
/*   Updated: 2023/01/24 09:05:04 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nexus.h>
#include <memory.h>
#include <stdlib.h>
#include <builtin.h>
#include <unistd.h>

void	command(t_parser_info info)
{
	if (info.cmd.builtin < 7)
	{
		if (info.cmd.builtin == EXIT)
			ft_exit(&info);
		if (info.cmd.builtin == PWD)
			ft_pwd(&info);
		if (info.cmd.builtin == CD)
			ft_cd(&info);
	}
}
