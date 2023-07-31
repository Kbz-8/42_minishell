/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:25:19 by vvaas             #+#    #+#             */
/*   Updated: 2023/07/31 19:31:05 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nexus.h>
#include <libft.h>
#include <stdio.h>
#include <stdbool.h>
#include <memory.h>

bool	is_flag(char *arg)
{
	int	i;

	i = 2;
	if (arg[0] == '-' && arg[1] == 'n')
	{
		while (arg[i] == 'n')
			i++;
		if (arg[i])
			return (false);
	}
	else
		return (false);
	return (true);
}

void	print_echo(t_parser_info *info)
{
	int		i;
	bool	newline;

	newline = true;
	i = 1;
	while (info->args[i] && is_flag((char *)info->args[i]))
	{
		newline = false;
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
}

void	ft_echo(t_parser_info *info)
{
	if (info->args[1] == NULL)
		printf("\n");
	else
		print_echo(info);
}
