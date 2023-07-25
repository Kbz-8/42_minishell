/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 13:25:28 by maldavid          #+#    #+#             */
/*   Updated: 2023/07/25 22:00:04 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nexus.h>
#include <libft.h>
#include <memory.h>
#include <ast.h>
#include <stdint.h>

char	*manage_var(char *str, char **name)
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

static size_t	manage_last_return(t_command_data *data, char *str)
{
	size_t	i;
	char	*ptr;
	char	*itoa;

	i = 0;
	ptr = str + 1;
	while (ptr[i])
	{
		if (!ft_isspace(ptr[i]) && ptr[i] != '?')
			return (0);
		if (ptr[i] == '?')
		{
			itoa = ft_itoa(get_env_data()->last_return);
			ft_strcpy(data->ptr + data->i, itoa);
			data->i += ft_strlen(itoa);
			dealloc(itoa);
			return (i + 2);
		}
		i++;
	}
	return (0);
}

void	include_var(t_command_data *data, char **str)
{
	size_t	var_val_size;

	if (*(*str) == '~')
	{
		ft_strcpy(data->ptr + data->i, get_env_var("HOME"));
		data->i += ft_strlen(get_env_var("HOME"));
		(*str)++;
		return ;
	}
	var_val_size = manage_last_return(data, *str);
	if (var_val_size != 0)
		(*str) += var_val_size;
	if (var_val_size != 0)
		return ;
	data->var_value = manage_var(*str + 1, &data->var_name);
	if (data->var_value == NULL)
		(*str) += ft_strlen(data->var_name) + 1;
	if (data->var_value == NULL)
		return ;
	var_val_size = ft_strlen(data->var_value);
	manage_realloc(&data->ptr, &data->alloc_size, data->i + var_val_size);
	ft_strcpy(data->ptr + data->i, data->var_value);
	data->i += var_val_size;
	(*str) += ft_strlen(data->var_name) + 1;
	dealloc(data->var_name);
}
