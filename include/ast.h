/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 02:00:58 by maldavid          #+#    #+#             */
/*   Updated: 2023/01/19 04:34:25 by maldavid         ###   ########.fr       */
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
	COMMAND,
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

typedef struct s_token_list
{
	e_node_type			type;
	const char			*str;
	struct s_token_list	*next;
}	t_token_list;

t_ast			*generate_ast(const char *entry);
t_ast_node		*new_ast_node(enum e_node_type type, const char *str);
t_ast_node		*add_pipe(t_ast_node *parent, t_ast_node *l, t_ast_node *r);
t_token_list	*generate_token_list(const char *entry);

#endif
