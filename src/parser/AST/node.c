/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 02:33:34 by maldavid          #+#    #+#             */
/*   Updated: 2023/01/19 05:22:19 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ast.h>
#include <memory.h>
#include <libft.h>

t_ast_node	*new_ast_node(enum e_node_type type, const char *str)
{
	t_ast_node	*node;

	node = alloc(sizeof(t_ast_node));
	ft_bzero(node, sizeof(t_ast_node));
	node->type = type;
	node->str = str;
	return (node);
}

t_ast_node	*add_pipe(t_ast_node *parent, t_ast_node *l, t_ast_node *r)
{
	if (parent == NULL)
	{
		parent = new_ast_node(PIPE, NULL);
		parent->l_child = l;
		parent->r_child = r;
		return (parent);
	}
	parent->r_child = new_ast_node(PIPE, NULL);
	parent->r_child->l_child = l;
	parent->r_child->r_child = r;
	return (parent->r_child);
}
