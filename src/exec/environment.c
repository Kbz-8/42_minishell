/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 22:53:44 by vvaas             #+#    #+#             */
/*   Updated: 2023/07/19 13:30:06 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nexus.h>
#include <libft.h>
#include <utils.h>
#include <memory.h>

bool	env_key_exist(char *key)
{
	t_env_var *env;

	env = get_env_data()->vars;
	while (env)
	{
		if (ft_strcmp(key, env->key) == 0)
			return (true);
		env = env->next;
	}
	return (false);
}

bool is_environment(char *input)
{
	if (!ft_strchr(input, '='))
		return (0);
	return (1);
}

void	add_env(char *input)
{
	char	*key;
	char	*value;
	char	*found;

	if (input == NULL)
		return ;
	found = ft_strchr(input, '=');
	if (found != NULL)
	{
		key = ft_strndup(input, found - input);
		value = ft_strdup(found + 1);
	}
	else
	{
		key = input;
		value = NULL;
	}
	if (get_env_var(key) == NULL)
		add_env_var(key, value);
	else
		modify_env_var(key, key, value);
}
