/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 13:25:28 by maldavid          #+#    #+#             */
/*   Updated: 2023/01/21 13:47:31 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nexus.h>
#include <libft.h>
#include <memory.h>

char	*manage_var_in_quotes(char *str)
{
	char	*var_name;
	char	*var_value;
	int		i;

	var_name = alloc(ft_strlen(str) + 1);
	i = 0;
	while (*str && !isspace(*str))
	{
		var_name[i] = *str;
		i++;
		str++;
	}
	var_value = get_env_var(var_name);
	if (var_value == NULL)
		return (NULL);
	dealloc(var_name);
	return (var_value);
}
