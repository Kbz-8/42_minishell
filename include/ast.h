/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 02:00:58 by maldavid          #+#    #+#             */
/*   Updated: 2023/01/19 02:12:49 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

enum e_node_type
{
	PIPE,
	SIMPLE_RED_L,
	SIMPLE_RED_R,
	DOUBLE_RED_L,
	DOUBLE_RED_R,
	LEAF,
};

typedef struct s_ast_node
{
	enum e_node_type	type;
	const char			*str;
	struct s_ast_node	*l_child;
	struct s_ast_node	*r_child;
}	t_ast_node;

typedef struct	s_ast
{
	t_ast_node	*root;
}	t_ast;

t_ast		*generate_ast(const char *entry);
t_ast_node	*new_ast_node(enum e_node_type type, const char *str);

#endif
