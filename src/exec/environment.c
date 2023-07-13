/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 22:53:44 by vvaas             #+#    #+#             */
/*   Updated: 2023/07/13 18:12:53 by vvaas            ###   ########.fr       */
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
	char **values;
	int i;

	i = 0;
	values = alloc(ft_strlen(input) * sizeof(char));
	while (input[i] != '=')
		i++;
	values[0] = ft_strndup(input, i);
	values[1] = ft_strndup(&input[i + 1], ft_strlen(&input[i]));
	if (get_env_var(values[0]) == NULL)
		add_env_var(values[0], values[1]);
	else
		modify_env_var(values[0], values[0], values[1]);
}