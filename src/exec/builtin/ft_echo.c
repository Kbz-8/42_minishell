/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:25:19 by vvaas             #+#    #+#             */
/*   Updated: 2023/07/25 21:02:10 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nexus.h>
#include <libft.h>
#include <stdio.h>
#include <stdbool.h>
#include <memory.h>

void	print_echo(t_parser_info *info, int i, bool newline)
{
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

void	ft_echo(t_parser_info *info)
{
	bool	newline;
	int		i;

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
	print_echo(info, i, newline);
}
