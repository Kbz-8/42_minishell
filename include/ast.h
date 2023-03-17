/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 02:00:58 by maldavid          #+#    #+#             */
/*   Updated: 2023/03/17 17:36:37 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

#include <nexus.h>

enum e_node_type
{
	PIPE = 0,
	SIMPLE_RED_L = 1,
	SIMPLE_RED_R = 2,
	DOUBLE_RED_R = 3,
	HERE_DOC = 4,
	COMMAND = 5,
};

typedef struct s_token
{
	enum e_node_type	type;
	char				*str;
}	t_token;

typedef struct s_token_list
{
	t_token				*token;
	struct s_token_list	*prev;
	struct s_token_list	*next;
}	t_token_list;

typedef struct s_ast_node
{
	t_token				*token;
	struct s_ast_node	*l_child;
	struct s_ast_node	*r_child;
}	t_ast_node;

typedef struct s_ast
{
	t_ast_node	*root;
}	t_ast;

t_ast			*generate_ast(t_token_list *list);
t_token_list	*generate_token_list(char *entry);
void			to_ast(t_ast *ast, t_token_list *list);
t_parser_info	*visit_ast(t_ast *ast);

#endif
