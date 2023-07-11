/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 02:29:32 by vvaas             #+#    #+#             */
/*   Updated: 2023/07/11 19:09:43 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nexus.h>
#include <utils.h>
#include <libft.h>

void	print_sorted_env(void)
{
	t_env_var	*var;
	char *lowest;

	var = get_env_data()->vars;
	lowest = var->key;
	while (var)
	{
		if (ft_strcmp(var->key, lowest) < 0)
			lowest = var->key;
		var = var->next;
	}
	ft_printf("%s\n", lowest);
}

void	ft_export(t_parser_info *info)
{
	int i;

	i = 1;
	if (info->args[1] == NULL)
		print_sorted_env();
	while (info->args[i])
	{
		if (is_environment((char *)info->args[i])) // big placeholder
			add_env((char *)info->args[i]);
		i++;
	}
}