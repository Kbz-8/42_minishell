/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:33:00 by maldavid          #+#    #+#             */
/*   Updated: 2023/03/01 18:33:14 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ast.h>
#include <stddef.h>

/*void	manage_redirection(t_ast_node *node)
{
	(void)node;
}

void	manage_pipe(t_ast_node *node)
{
	(void)node;
}

void	visit(t_ast_node *node)
{
	if (node->l_child != NULL)
		visit(node->l_child);
	if (node->token->token->type > 0 && node->token->token->type < 4)
		manage_redirection(node);
	if (node->token->token->type == PIPE)
		manage_pipe(node);
	if (node->r_child != NULL)
		visit(node->r_child);
}

void	add_leaves(t_ast *ast)
{
	if (ast->root == NULL)
		return ;
	visit(ast->root);
}

*/