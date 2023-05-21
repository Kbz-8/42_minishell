/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 13:25:28 by maldavid          #+#    #+#             */
/*   Updated: 2023/05/21 16:17:00 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nexus.h>
#include <libft.h>
#include <memory.h>
#include <ast.h>
#include <stdint.h>

char	*manage_var_in_quotes(char *str, char **name)
{
	char	*var_value;
	int		i;

	*name = ft_memalloc(ft_strlen(str) + 1);
	i = 0;
	while (*str && !ft_isspace(*str) && *str != '"')
	{
		(*name)[i] = *str;
		i++;
		str++;
	}
	var_value = (char *)get_env_var(*name);
	if (var_value == NULL)
		return (NULL);
	return (var_value);
}

void	free_token_list(t_token_list *list)
{
	t_token_list	*ptr;

	while (list != NULL)
	{
		ptr = list->next;
		dealloc(list);
		list = ptr;
	}
}

void	manage_realloc(char **ptr, uint32_t *alloc_size, uint32_t i)
{
	if (i >= *alloc_size)
	{
		*alloc_size += i + 255;
		*ptr = realloc_but_not_the_std_lib(*ptr, *alloc_size + 1);
	}
}

void	include_var(t_command_data *data, char **str)
{
	size_t	var_val_size;

	data->var_value = manage_var_in_quotes(*str + 1, &data->var_name);
	if (data->var_value == NULL)
	{
		data->ptr[data->i++] = '$';
		(*str)++;
		return ;
	}
	var_val_size = ft_strlen(data->var_value);
	manage_realloc(&data->ptr, &data->alloc_size, data->i + var_val_size);
	ft_strcpy(data->ptr + data->i, data->var_value);
	data->i += var_val_size;
	(*str) += ft_strlen(data->var_name) + 1;
	dealloc(data->var_name);
}
