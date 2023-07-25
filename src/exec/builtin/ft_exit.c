/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:13:27 by vvaas             #+#    #+#             */
/*   Updated: 2023/07/25 21:05:58 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <memory.h>
#include <nexus.h>
#include <libft.h>
#include <errors.h>
#include <stdbool.h>
#include <errors.h>
#include <memory.h>

static bool	ft_is_number(char *arg)
{
	unsigned int	i;

	i = 0;
	if (arg[i] == '\0')
		return (0);
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	while (ft_isdigit(arg[i]))
		i++;
	if (i != ft_strlen(arg))
		return (0);
	return (1);
}

void	ft_exit(t_parser_info *info)
{
	unsigned int	exitcode;

	if (!info->args[1])
	{
		allfree();
		exit(get_env_data()->last_return);
	}
	if (!ft_is_number((char *)info->args[1]))
	{
		ft_printf("exit\nminishell: exit: %s:  numeric argument required\n", \
		info->args[1]);
		allfree();
		exit(2);
	}
	if (info->args[2])
		ft_printf("exit\nminishell: exit: too many arguments\n", info->args[1]);
	else
	{
		exitcode = ft_atoi(info->args[1]);
		allfree();
		exit(exitcode % 256);
	}
}
