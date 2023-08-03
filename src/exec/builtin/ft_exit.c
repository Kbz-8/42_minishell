/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:13:27 by vvaas             #+#    #+#             */
/*   Updated: 2023/08/03 18:10:45 by vvaas            ###   ########.fr       */
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
#include <unistd.h>

void	hard_close(bool	hard)
{
	int	i;

	i = 1023;
	while (i - 2)
		close(i--);
	while (hard && i + 1)
		close(i--);
}

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

static unsigned int	exitcode(t_parser_info *info)
{
	unsigned int	exitcode;

	exitcode = ft_atoi(info->args[1]);
	exitcode %= 256;
	return (exitcode);
}

void	ft_exit(t_parser_info *info)
{
	unsigned int	existcode;

	if (!info || !info->args[1])
	{
		hard_close(true);
		ft_printf("exit\n");
		allfree();
		exit(get_env_data()->last_return);
	}
	if (!ft_is_number((char *)info->args[1]))
	{
		ft_printf("exit\nminishell: exit: %s:  numeric argument required\n", \
		info->args[1]);
		hard_close(true);
		allfree();
		exit(2);
	}
	if (!info->args[2])
	{
		existcode = exitcode(info);
		hard_close(true);
		allfree();
		exit(existcode);
	}
	ft_putstr("exit\nminishell: exit: too many arguments\n");
}
