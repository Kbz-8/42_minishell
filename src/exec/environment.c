/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 22:53:44 by vvaas             #+#    #+#             */
/*   Updated: 2023/06/24 20:30:20 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nexus.h>
#include <libft.h>
#include <utils.h>

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
	if (env_key_exist(values[0]))
	{
		modify_env_var(values[0], values[0], values[1]);
		return ;
	}
	add_env_var(values[0], values[1]);
}