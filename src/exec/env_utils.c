/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 00:01:34 by vvaas             #+#    #+#             */
/*   Updated: 2023/08/03 22:40:59 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nexus.h>
#include <libft.h>

char	*get_key(const char *arg)
{
	int	i;

	i = 0;
	while (arg[i] && arg[i] != '=' && (arg[i] != '+' && arg[i + 1] != '='))
		i++;
	if (i == 0)
		return (NULL);
	return (ft_strndup(arg, i + 1));
}

bool	is_append(const char *arg)
{
	int	i;

	i = 0;
	while (arg[i] && arg[i] != '+')
		i++;
	if (arg[i] == '+' && arg[i + 1] == '=')
		return (true);
	return (false);
}

void	ft_nullenv(char **input, char **found, char **key, char **val)
{
	*key = ft_strndup(*input, *found - *input);
	*val = ft_strdup(*found + 1);
	if (ft_strlen(*val) == 0)
		*val = ft_strdup("");
	return ;
}
