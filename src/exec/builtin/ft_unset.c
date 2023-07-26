/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 00:28:11 by vvaas             #+#    #+#             */
/*   Updated: 2023/07/26 14:47:41 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nexus.h>
#include <libft.h>

void	ft_unset(t_parser_info *info)
{
	int	i;

	i = 1;
	while (info->args[i] != NULL)
	{
		remove_env_var((char *)info->args[i]);
		i++;
	}
	get_env_data()->last_return = 0;
}
