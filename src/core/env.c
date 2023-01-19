/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 01:48:34 by maldavid          #+#    #+#             */
/*   Updated: 2023/01/19 15:49:11 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nexus.h>
#include <memory.h>
#include <libft.h>

t_env	g_env;

t_env	*get_env_data(void)
{
	return (&g_env);
}

void	add_env_var(char *key, char* value)
{
	t_env_var	*new;

	new = alloc(sizeof(t_env_var));
	new->key = alloc(ft_strlen(key) + 1);
	ft_bzero(new->key, ft_strlen(key) + 1);
	ft_strcpy(new->key, key);
	new->value = alloc(ft_strlen(value) + 1);
	ft_bzero(new->value, ft_strlen(value) + 1);
	ft_strcpy(new->value, value);
	new->next = get_env_data()->vars;
	get_env_data()->vars = new;
}
