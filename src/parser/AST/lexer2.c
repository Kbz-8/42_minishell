/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 13:25:28 by maldavid          #+#    #+#             */
/*   Updated: 2023/01/22 17:08:24 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nexus.h>
#include <libft.h>
#include <memory.h>

const char	*manage_var_in_quotes(char *str)
{
	char		*var_name;
	const char	*var_value;
	int			i;

	var_name = alloc(ft_strlen(str) + 1);
	ft_bzero(var_name, ft_strlen(str) + 1);
	i = 0;
	while (*str && !ft_isspace(*str) && *str != '"')
	{
		var_name[i] = *str;
		i++;
		str++;
	}
	var_value = get_env_var(var_name);
	dealloc(var_name);
	if (var_value == NULL)
		return (NULL);
	return (var_value);
}
