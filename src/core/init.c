/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:22:37 by maldavid          #+#    #+#             */
/*   Updated: 2023/07/25 23:50:49 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nexus.h>
#include <stdlib.h>
#include <interactive.h>
#include <memory.h>
#include <libft.h>

static char	*shlvl(char *lvl)
{
	int		i;
	
	i = ft_atoi(lvl);
	i++;
	return (ft_itoa(i));
}

void	init_minishell(char **env)
{
	int		i;
	char	*key;
	char	*value;
	bool	sh_lvl;

	ft_set_internal_malloc(alloc);
	ft_set_internal_free(dealloc);
	i = 0;
	sh_lvl = false;
	while (env[i] != NULL)
	{
		value = ft_strdup(ft_strchr(env[i], '=') + 1);
		key = ft_strndup(env[i], ft_strchr(env[i], '=') - env[i]);
		if (ft_strcmp(key, "SHLVL") == 0)
			value = shlvl(value);
		if (ft_strcmp(key, "SHLVL") == 0)
			sh_lvl = true;
		add_env_var(key, value);
		i++;
	}
	if (!sh_lvl)
		add_env_var("SHLVL", "0");
	init_sig();
	ft_putstr("\nWelcome to Minishell by vvaas and maldavid !\n");
}
