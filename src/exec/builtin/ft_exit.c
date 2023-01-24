/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:13:27 by vvaas             #+#    #+#             */
/*   Updated: 2023/01/24 09:08:24 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <memory.h>
#include <nexus.h>
#include <libft.h>
#include <errors.h>
#include <stdbool.h>
#include <errors.h>

static bool	ft_is_number(char *arg)
{
	unsigned int i;

	i = 0;
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
	if (ft_atoi(arg) > 255 || ft_atoi(arg) < 0)
		return (0);
	return (1);
}

int	ft_exit(t_parser_info *info)
{
	if (!ft_is_exit_code((char *)info->args))
		return (256);
	return (ft_atoi(info->args));
}
