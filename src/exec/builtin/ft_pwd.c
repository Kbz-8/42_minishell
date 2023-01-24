/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 08:24:55 by vvaas             #+#    #+#             */
/*   Updated: 2023/01/24 09:26:17 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <nexus.h>
#include <libft.h>
#include <errors.h>

int	ft_pwd(t_parser_info *info)
{
	if (info->args)
	{
		report(ERROR, E_TOO_MANY_ARGS);
		return (-1);
	}
	ft_putstr((char *)get_env_var("PWD"));
	return (0);
}