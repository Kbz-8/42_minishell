/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:13:27 by vvaas             #+#    #+#             */
/*   Updated: 2023/07/17 23:35:39 by vvaas            ###   ########.fr       */
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
	unsigned int i;

	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	while (ft_isdigit(arg[i]))
		i++;
	if (i != ft_strlen(arg))
		return (0);
	return (1);
}

static bool	ft_is_exit_code(char *arg)
{
	if (!ft_is_number(arg))
	{
		report(ERROR, NUMBER_REQUIRED);
		return (0);
	}
	return (1);
}

int	ft_exit(t_parser_info *info)
{
	unsigned int exitcode;

	exitcode = ft_atoi(info->args[1]);
	if (!info->args[1])
		exit(get_env_data()->last_return);
	exitcode = ft_atoi(info->args[1]);
	if (!ft_is_exit_code((char *)info->args[1]))
		return (256);
	allfree();
	get_env_data()->loop = 0;
	exit(exitcode % 256);
	return (exitcode);
}
