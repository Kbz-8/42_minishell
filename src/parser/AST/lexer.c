/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 04:34:34 by maldavid          #+#    #+#             */
/*   Updated: 2023/08/03 22:55:48 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ast.h>
#include <memory.h>
#include <libft.h>
#include <stdbool.h>
#include <stdint.h>

void	manage_realloc(char **ptr, uint32_t *alloc_size, uint32_t i);
void	include_var(t_command_data *data, char **str);

t_token_list	*new_token(char *str)
{
	t_token_list	*list;
	size_t			size;

	list = alloc(sizeof(t_token_list));
	list->next = NULL;
	list->token = alloc(sizeof(t_token));
	size = ft_strlen(str) + 1;
	list->token->str = ft_memalloc(size);
	ft_strcpy(list->token->str, str);
	if (str[0] == '|')
		list->token->type = AST_PIPE;
	else if (str[0] == '>' && str[1] == '>')
		list->token->type = AST_DOUBLE_RED_R;
	else if (str[0] == '<' && str[1] == '<')
		list->token->type = AST_HERE_DOC;
	else if (str[0] == '>')
		list->token->type = AST_SIMPLE_RED_R;
	else if (str[0] == '<')
		list->token->type = AST_SIMPLE_RED_L;
	else
		list->token->type = AST_COMMAND;
	return (list);
}

static void	add_token_to_list(t_token_list **list, t_token_list *token)
{
	t_token_list	*ptr;

	if (*list == NULL)
	{
		*list = token;
		token->prev = NULL;
		return ;
	}
	ptr = *list;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = token;
	token->prev = ptr;
}

static void	add_redirection(t_token_list **list, char **str)
{
	if ((*str)[0] == '>' && (*str)[1] == '>')
	{
		add_token_to_list(list, new_token(">>"));
		*str += 2;
	}
	else if ((*str)[0] == '<' && (*str)[1] == '<')
	{
		add_token_to_list(list, new_token("<<"));
		*str += 2;
	}
	else if ((*str)[0] == '<')
	{
		add_token_to_list(list, new_token("<"));
		(*str)++;
	}
	else if ((*str)[0] == '>')
	{
		add_token_to_list(list, new_token(">"));
		(*str)++;
	}
}

static void	add_command(t_token_list **list, char **str)
{
	t_command_data	data;

	ft_memset(&data, 0, sizeof(t_command_data));
	data.alloc_size = 2048;
	data.ptr = ft_memalloc(data.alloc_size);
	while (*(*str) && ((data.sq || data.dq) || !ft_strchr("|<>", *(*str))))
	{
		manage_realloc(&data.ptr, &data.alloc_size, data.i);
		if (*(*str) == '\'' && !data.dq)
			data.sq = !data.sq;
		else if (*(*str) == '"' && !data.sq)
			data.dq = !data.dq;
		else if ((*(*str) == '$' && !data.sq) || \
				(*(*str) == '~' && !data.dq && !data.sq))
		{
			include_var(&data, str);
			continue ;
		}
		if ((*(*str) == '\'' && data.dq) || (*(*str) == '"' && data.sq) \
				|| !ft_strchr("'\"", *(*str)))
			data.ptr[data.i++] = *(*str);
		(*str)++;
	}
	data.ptr[data.i] = 0;
	add_token_to_list(list, new_token(data.ptr));
}

t_token_list	*generate_token_list(char *entry)
{
	t_token_list	*list;

	list = NULL;
	while (*entry)
	{
		if (*entry == '|')
		{
			add_token_to_list(&list, new_token("|"));
			entry++;
		}
		else if (*entry == '<' || *entry == '>')
			add_redirection(&list, &entry);
		else if (!ft_isspace(*entry))
			add_command(&list, &entry);
		else
			entry++;
	}
	return (list);
}
