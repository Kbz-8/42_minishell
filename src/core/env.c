/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 01:48:34 by maldavid          #+#    #+#             */
/*   Updated: 2023/05/26 19:19:13 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nexus.h>
#include <memory.h>
#include <libft.h>

t_env	*get_env_data(void)
{
	static t_env	env;

	env.last_return = 0;
	return (&env);
}

void	add_env_var(char *key, char *value)
{
	t_env_var	*new;

	new = alloc(sizeof(t_env_var));
	new->key = ft_strdup(key);
	new->value = ft_strdup(value);
	new->next = get_env_data()->vars;
	get_env_data()->vars = new;
}

const char	*get_env_var(char *key)
{
	t_env_var	*ptr;

	ptr = get_env_data()->vars;
	while (ptr && ft_strcmp(ptr->key, key) != 0)
		ptr = ptr->next;
	if (ptr && ft_strcmp(ptr->key, key) == 0)
		return ((const char *)ptr->value);
	return (NULL);
}
