/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 02:29:32 by vvaas             #+#    #+#             */
/*   Updated: 2023/06/27 21:31:41 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nexus.h>
#include <utils.h>

void	ft_export(t_parser_info *info)
{
	int i;

	i = 1;
	while (info->args[i])
	{
		if (is_environment((char *)info->args[i])) // big placeholder
			add_env((char *)info->args[i]);
		i++;
	}
}