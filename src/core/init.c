/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:22:37 by maldavid          #+#    #+#             */
/*   Updated: 2023/07/25 20:54:03 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nexus.h>
#include <stdlib.h>
#include <interactive.h>
#include <memory.h>
#include <libft.h>

void	init_minishell(char **env)
{
	int		i;
	char	*key;
	char	*value;

	ft_set_internal_malloc(alloc);
	ft_set_internal_free(dealloc);
	i = 0;
	while (env[i] != NULL)
	{
		value = ft_strdup(ft_strchr(env[i], '=') + 1);
		key = ft_strndup(env[i], ft_strchr(env[i], '=') - env[i]);
		add_env_var(key, value);
		ft_free(key);
		ft_free(value);
		i++;
	}
	get_env_data()->last_return = 0;
	get_env_data()->listen = true;
	get_env_data()->fd = -1;
	get_env_data()->fd_input_save = -1;
	init_sig();
	ft_putstr("\nWelcome to Minishell by vvaas and maldavid !\n");
}
