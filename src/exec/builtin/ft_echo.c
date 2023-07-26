/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:25:19 by vvaas             #+#    #+#             */
/*   Updated: 2023/07/26 14:57:31 by maldavid         ###   ########.fr       */
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
}

void	ft_echo(t_parser_info *info)
{
	if (info->args[1] == NULL)
		printf("\n");
	else if (!ft_strcmp(info->args[1], "-n"))
		print_echo(info, 2, false);
	else
		print_echo(info, 1, true);
}
