/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 04:34:34 by maldavid          #+#    #+#             */
/*   Updated: 2023/01/19 05:23:38 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ast.h>
#include <memory.h>
#include <libft.h>

static t_token_list	*new_token(char *str)
{
	t_token_list	*list;

	list = alloc(sizeof(t_token_list));
	list->next = NULL;
	list->str = alloc(ft_strlen(str));
	ft_strcpy(list->str, str);
	if (ft_strchr(str, '|') != NULL)
		list->type = PIPE;
	else if (ft_strstr(str, ">>") != NULL)
		list->type = DOUBLE_RED_R;
	else if (ft_strstr(str, "<<") != NULL)
		list->type = DOUBLE_RED_L;
	else if (ft_strchr(str, '>') != NULL)
		list->type = SIMPLE_RED_R;
	else if (ft_strchr(str, '<') != NULL)
		list->type = SIMPLE_RED_L;
	else
		list->type = COMMAND;
	return (list);
}

static void	add_token_to_list(t_token_list **list, t_token_list *token)
{
	t_token_list	*ptr;

	if (*list == NULL)
	{
		*list = token;
		return ;
	}
	ptr = *list;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = token;
}

static void	add_redirection(t_token_list **list, char *str)
{
	if (ft_strstr(str, "<<"))
		add_token_to_list(list, new_token("<<"));
	else if (ft_strstr(str, ">>"))
		add_token_to_list(list, new_token(">>"));
	else if (*str == '<')
		add_token_to_list(list, new_token("<"));
	else if (*str == '>')
		add_token_to_list(list, new_token(">"));
}

static void	add_command(t_token_list **list, char **str)
{
	size_t	size;
	char	*ptr;

	size = 0;
	ptr = *str;
	while (*ptr != '|' && *ptr != '<' && *ptr != '>' && *ptr != 0)
	{
		size++;
		ptr++;
	}
	ptr = alloc(size);
	ft_memcpy(ptr, *str, size);
	*str += size;
	add_token_to_list(list, new_token(ptr));
}

t_token_list	*generate_token_list(char *entry)
{
	t_token_list	*list;

	while (*entry)
	{
		if (*entry == '|')
		{
			add_token_to_list(&list, new_token("|"));
			entry++;
		}
		else if (*entry == '<' || *entry == '>')
		{
			add_redirection(&list, entry);
			entry++;
		}
		else
			add_command(&list, &entry);
	}
	return (list);
}
