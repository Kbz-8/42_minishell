/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 22:53:44 by vvaas             #+#    #+#             */
/*   Updated: 2023/06/20 23:20:51 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nexus.h>
#include <libft.h>
#include <utils.h>

bool is_environment(char *input)
{
	char **temp;

	if (!ft_strchr(input, '='))
		return (0);
	temp = ft_split(input, '=');
	if (temp[2])
	{
		ft_freesplit(temp);
		return (0);
	}
	ft_freesplit(temp);
	return (1);
}

void	add_env(char *input)
{
	char **values;

	values = ft_split(input, '=');
	add_env_var(values[0], values[1]);
}