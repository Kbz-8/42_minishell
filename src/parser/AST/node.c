/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 02:33:34 by maldavid          #+#    #+#             */
/*   Updated: 2023/03/09 17:42:05 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ast.h>
#include <memory.h>
#include <libft.h>
#include <stdbool.h>

t_ast_node	*new_ast_node(t_token *token, t_ast_node *l, t_ast_node *r)
{
	t_ast_node	*node;

	node = alloc(sizeof(t_ast_node));
	node->token = token;
	node->r_child = r;
	node->l_child = l;
	return (node);
}

static t_token_list	*get_sub_list(t_token_list *list, size_t len)
{
	t_token_list	*new_list;
	t_token_list	*ptr;

	new_list = alloc(sizeof(t_token_list));
	ptr = new_list;
	while (len > 0 && list != NULL)
	{
		ptr->token = list->token;
		ptr->next = alloc(sizeof(t_token_list));
		ptr = ptr->next;
		list = list->next;
		len--;
	}
	return (new_list);
}

static t_token_list	*separator_position(t_token_list *list, int *pos)
{
	*pos = 0;
	while (list != NULL)
	{
		ft_printf("%s\n", list->token->str);
		if (list->token->type != COMMAND && list->token->type != HERE_DOC)
			return (list);
		(*pos)++;
		list = list->next;
	}
	return (NULL);
}

static void	token_list_to_ast(t_ast_node *ast, t_token_list *list)
{
	t_token_list	*sep;
	t_token_list	*l_sub;
	t_token_list	*r_sub;
	int				pos;

	sep = separator_position(list, &pos);
	ast = new_ast_node(list->token, NULL, NULL);
	if (sep == NULL)
		return ;
	l_sub = get_sub_list(list, pos);
	r_sub = get_sub_list(sep->next, -1);
	token_list_to_ast(ast->l_child, l_sub);
	token_list_to_ast(ast->r_child, r_sub);
	dealloc(l_sub);
	dealloc(r_sub);
}

void	to_ast(t_ast *ast, t_token_list *list)
{
	// TODO : manage env vars
	token_list_to_ast(ast->root, list);
}
