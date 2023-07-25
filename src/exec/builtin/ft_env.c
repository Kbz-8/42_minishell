/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:41:30 by vvaas             #+#    #+#             */
/*   Updated: 2023/07/25 21:05:28 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nexus.h>
#include <errors.h>
#include <libft.h>

int	ft_env(t_parser_info *info)
{
	t_env_var	*args;

	if (info->args[1])
	{
		report(ERROR, E_TOO_MANY_ARGS);
		get_env_data()->last_return = 127;
		return (-1);
	}
	args = get_env_data()->vars;
	while (args->next)
	{
		if (args->value[0] != '\0')
			ft_printf("%s=%s\n", args->key, args->value);
		args = args->next;
	}
	get_env_data()->last_return = 0;
	return (0);
}
