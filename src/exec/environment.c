/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 22:53:44 by vvaas             #+#    #+#             */
/*   Updated: 2023/07/29 00:10:15 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nexus.h>
#include <libft.h>
#include <utils.h>
#include <memory.h>
#include <utils.h>
#include <unistd.h>

bool	env_key_exist(char *key)
{
	t_env_var	*env;

	env = get_env_data()->vars;
	while (env)
	{
		if (ft_strcmp(key, env->key) == 0)
			return (true);
		env = env->next;
	}
	return (false);
}

void	append_env(char *input)
{
	int		i;
	char	*key;
	char	*value;

	i = 0;
	key = get_key(input);
	value = ft_strdup(input) + 2 + ft_strlen(key);
	if (key_exists(key))
		modify_env_var(key, key, ft_strjoin(get_env_var(key), value));
	else
		add_env_var(key, value);
}

void	add_env(char *input, bool append)
{
	char	*key;
	char	*value;
	char	*found;

	if (input == NULL)
		return ;
	if (append)
	{
		append_env(input);
		return ;
	}
	found = ft_strchr(input, '=');
	if (found != NULL)
		ft_nullenv(&input, &found, &key, &value);
	else
	{
		key = input;
		value = NULL;
	}
	if (!key_exists(key))
		add_env_var(key, value);
	else
		modify_env_var(key, key, value);
}

char	**create_tab(char **env_tab, t_env_var *args)
{
	int	i;

	i = 0;
	while (args->next)
	{
		env_tab[i] = alloc((ft_strlen(args->key) + 2 + \
		ft_strlen(args->value)) * sizeof(char));
		ft_strcpy(env_tab[i], args->key);
		ft_strcat(env_tab[i], "=");
		if (args->value == NULL)
			ft_strcat(env_tab[i], "\0");
		else
			ft_strcat(env_tab[i], args->value);
		args = args->next;
		i++;
	}
	env_tab[i] = NULL;
	return (env_tab);
}

int	ft_setcwd(t_parser_info *info)
{
	char	*buffer;

	if (check_validity((char *)info->args[1]) == 0)
		return (0);
	modify_env_var("OLDPWD", "OLDPWD", getcwd(NULL, 0));
	if (!get_env_var("PWD"))
		remove_env_var("OLDPWD");
	chdir(info->args[1]);
	buffer = getcwd(NULL, 0);
	modify_env_var("PWD", "PWD", buffer);
	free(buffer);
	get_env_data()->last_return = 0;
	return (0);
}
