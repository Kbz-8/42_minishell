/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 04:34:34 by maldavid          #+#    #+#             */
/*   Updated: 2023/02/28 19:04:56 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ast.h>
#include <memory.h>
#include <libft.h>
#include <stdbool.h>

char	*manage_var_in_quotes(char *str);

static t_token_list	*new_token(char *str)
{
	t_token_list	*list;
	size_t			size;

	list = alloc(sizeof(t_token_list));
	list->next = NULL;
	list->token = alloc(sizeof(t_token));
	size = ft_strlen(str) + 1;
	list->token->str = alloc(size);
	ft_bzero(list->token->str, size);
	ft_strcpy(list->token->str, str);
	if (str[0] == '|')
		list->token->type = PIPE;
	else if (str[0] == '>' && str[1] == '>')
		list->token->type = DOUBLE_RED_R;
	else if (str[0] == '<' && str[1] == '<')
		list->token->type = HERE_DOC;
	else if (str[0] == '>')
		list->token->type = SIMPLE_RED_R;
	else if (str[0] == '<')
		list->token->type = SIMPLE_RED_L;
	else
		list->token->type = COMMAND;
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
	if ((*str)[0] == '<' && (*str)[1] == '<')
	{
		add_token_to_list(list, new_token("<<"));
		*str += 2;
	}
	else if ((*str)[0] == '>' && (*str)[1] == '>')
	{
		add_token_to_list(list, new_token(">>"));
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
	size_t	size;
	char	*ptr;
	bool	begin_string;

	size = 0;
	ptr = *str;
	begin_string = false;
	while (*ptr != '|' && *ptr != '<' && *ptr != '>' && *ptr != 0)
	{
		if (*ptr == '"')
			begin_string = !begin_string;
		if (begin_string && *ptr == '$')
			manage_var_in_quotes(ptr + 1);
		size++;
		ptr++;
	}
	ptr = alloc(size + 1);
	ft_bzero(ptr, size + 1);
	ft_memcpy(ptr, *str, size);
	*str += size;
	add_token_to_list(list, new_token(ptr));
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
