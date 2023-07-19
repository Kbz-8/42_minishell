/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:25:19 by vvaas             #+#    #+#             */
/*   Updated: 2023/07/19 19:38:21 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nexus.h>
#include <libft.h>
#include <stdio.h>
#include <stdbool.h>
#include <memory.h>

void	ft_echo(t_parser_info *info)
{
	bool newline;
	int i;
	int j;

	j = -1;
	i = 1;
	newline = 1;
	if (!info->args[1])
	{
		printf("\n");
		return ;
	}
	if (!ft_strcmp(info->args[1], "-n"))
	{
		newline = 0;
		i++;
	}
	while (info->args[i])
	{
		printf("%s", info->args[i]);
		if (info->args[i + 1])
			printf(" ");
		i++;
	}
	if (newline)
		printf("\n");
	get_env_data()->last_return = 0;
	return ;
}