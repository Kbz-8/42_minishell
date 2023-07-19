/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:22:37 by maldavid          #+#    #+#             */
/*   Updated: 2023/07/19 22:48:38 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nexus.h>
#include <stdlib.h>
#include <interactive.h>
#include <memory.h>
#include <libft.h>

extern char	**environ;

void	init_minishell(void)
{
	int		i;
	char	*key;
	char	*value;

	ft_set_internal_malloc(alloc);
	ft_set_internal_free(dealloc);
	i = 0;
	while (environ[i] != NULL)
	{
		value = ft_strdup(ft_strchr(environ[i], '=') + 1);
		key = ft_strndup(environ[i], \
						(t_size)(ft_strchr(environ[i], '=') - environ[i]));
		add_env_var(key, value);
		ft_free(key);
		ft_free(value);
		i++;
	}
	get_env_data()->last_return = 0;
	get_env_data()->listen = true;
	init_sig();
}
