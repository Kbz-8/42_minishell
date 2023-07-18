/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 01:48:34 by maldavid          #+#    #+#             */
/*   Updated: 2023/07/19 01:05:48 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nexus.h>
#include <memory.h>
#include <libft.h>

t_env	*get_env_data(void)
{
	static t_env	env;

	return (&env);
}

void	add_env_var(char *key, char *value)
{
	t_env_var	*new;

	new = alloc(sizeof(t_env_var));
	new->key = ft_strdup(key);
	if (value)
		new->value = ft_strdup(value);
	else
		new->value = ft_strdup("\0");
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

void	remove_env_var(char *key)
{
	t_env_var	*ptr;

	ptr = get_env_data()->vars;
	if (ptr == NULL)
		return ;
	if (ft_strcmp(key, ptr->key) == 0)
	{
		get_env_data()->vars = ptr->next;
		dealloc(ptr->key);
		dealloc(ptr->value);
		dealloc(ptr);
		return ;
	}
	while (ptr->next != NULL)
	{
		if (ft_strcmp(key, ptr->next->key) == 0)
		{
			ptr->next = ptr->next->next;
			dealloc(ptr->next->key);
			dealloc(ptr->next->value);
			dealloc(ptr->next);
			return ;
		}
		ptr = ptr->next;
	}
}

void	modify_env_var(char *key, char *new_key, char *new_value)
{
	t_env_var	*ptr;

	ptr = get_env_data()->vars;
	if (ptr == NULL)
		return ;
	if (!get_env_var(key))
		return ;
	while (ptr->next != NULL)
	{
		if (ft_strcmp(key, ptr->key) == 0)
		{
			dealloc(ptr->key);
			dealloc(ptr->value);
			ptr->key = ft_strdup(new_key);
			if (new_value)
				ptr->value = ft_strdup(new_value);
			else
				ptr->value = ft_strdup("\0");
			return ;
		}
		ptr = ptr->next;
	}
}
