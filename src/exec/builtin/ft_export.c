/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 02:29:32 by vvaas             #+#    #+#             */
/*   Updated: 2023/07/11 18:51:52 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nexus.h>
#include <utils.h>
#include <libft.h>

void	print_sorted_env(void)
{
	t_env_var	*var;
	t_env_var	*backup;
	char *lowest_key;

	backup = get_env_data()->vars;
	lowest_key = backup->key;
	while (var)
	{
		if (ft_strcmp(var->key, lowest_key) < 0)
			lowest_key = var->key;
		var = var->next;
	}
	ft_printf("%s\n", lowest_key);
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