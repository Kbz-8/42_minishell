/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 08:32:33 by vvaas             #+#    #+#             */
/*   Updated: 2023/06/27 23:29:04 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nexus.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_cd(t_parser_info *info)
{
	void *buffer;

	if (!info->args[1])
		chdir(get_env_var("HOME"));
	else
		chdir(info->args[1]);
	buffer = getcwd(NULL, 0);
	modify_env_var("PWD", "PWD", buffer);
	free(buffer);
	return (0);
}