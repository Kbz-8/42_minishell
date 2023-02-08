/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 02:33:34 by maldavid          #+#    #+#             */
/*   Updated: 2023/02/08 18:16:38 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ast.h>
#include <memory.h>
#include <libft.h>

t_ast_node	*new_ast_node(t_token_list *token, t_ast_node *l, t_ast_node *r)
{
	t_ast_node	*node;

	node = alloc(sizeof(t_ast_node));
	node->token = token;
	node->r_child = r;
	node->l_child = l;
	return (node);
}

void	add_pipes(t_ast *ast, t_token_list *list)
{
	t_ast_node	*ptr;

	while (list != NULL)
	{
		if (list->token->type == PIPE)
		{
			if (ast->root == NULL)
				ast->root = new_ast_node(list, NULL, NULL);
			else
			{
				ptr = ast->root;
				while (ptr->r_child != NULL)
					ptr = ptr->r_child;
				ptr->r_child = new_ast_node(list, NULL, NULL);
			}
		}
		list = list->next;
	}
}

static void	insert_redirection(t_ast_node *node, t_token_list *token)
{
	while (token->prev != NULL && token->prev->token->type != PIPE)
	{
		ft_printf("youpi\n");
		if (token->token->type != COMMAND && token->token->type != HERE_DOC)
		{
			node->l_child = new_ast_node(token, NULL, NULL);
			break ;
		}
		token = token->prev;
	}
}

void	add_redirections(t_ast *ast)
{
	t_ast_node		*ptr;
	t_token_list	*token;

	ptr = ast->root;
	if (ptr == NULL)
		return ;
	while (ptr->r_child != NULL)
	{
		token = ptr->token;
		if (token->token->type == PIPE)
			insert_redirection(ptr, token);
		ptr = ptr->r_child;
	}
	insert_redirection(ptr, token);
	while (token->next != NULL)
	{
		if (token->token->type != COMMAND && token->token->type != HERE_DOC)
		{
			ptr->r_child = new_ast_node(token, NULL, NULL);
			break ;
		}
		token = token->next;
	}
}
