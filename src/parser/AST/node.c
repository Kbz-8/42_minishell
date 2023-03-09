/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 02:33:34 by maldavid          #+#    #+#             */
/*   Updated: 2023/03/01 18:33:00 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ast.h>
#include <memory.h>
#include <libft.h>
#include <stdbool.h>

/*t_ast_node	*new_ast_node(t_token *token, t_ast_node *l, t_ast_node *r)
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
	while(len > 0 && list != NULL)
	{
		ptr->token = list->token;
		ptr->next = alloc(sizeof(t_token_list));
		ptr = ptr->next;
		list = list->next;
		len--;
	}
	return (new_token);
}

static t_token_list	*separator_position(t_token_list *list)
{
	while (list != NULL)
	{
		if (list->token->type != COMMAND && list->token->type != HERE_DOC)
			return (list);
		list = list->next;
	}
	return (NULL);
}

static void	token_list_to_ast(t_ast_node *ast, t_token_list *list)
{
	t_token_list	*sep;

	sep = separator_position(list);
	ast = new_ast_node(list->token, NULL, NULL);
	if (sep == NULL)
		return ;
	// token_list_to_ast(ast->l_child, )
}

void	to_ast(t_ast *ast, t_token_list *list)
{
	// TODO : manage env vars
	// token_list_to_ast(ast->root, list);
}

*/