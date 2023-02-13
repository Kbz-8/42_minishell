/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 02:00:58 by maldavid          #+#    #+#             */
/*   Updated: 2023/02/13 11:32:09 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

enum e_node_type
{
	PIPE,
	SIMPLE_RED_L,
	SIMPLE_RED_R,
	DOUBLE_RED_R,
	HERE_DOC,
	COMMAND,
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
	t_token_list		*token;
	struct s_ast_node	*l_child;
	struct s_ast_node	*r_child;
}	t_ast_node;

typedef struct s_ast
{
	t_ast_node	*root;
}	t_ast;

t_ast			*generate_ast(t_token_list *list);
t_token_list	*generate_token_list(char *entry);
t_ast_node		*new_ast_node(t_token_list *token, t_ast_node *l, t_ast_node *r);
void			add_pipes(t_ast *ast, t_token_list *list);
void			add_redirections(t_ast *ast);
void			add_leaves(t_ast *ast);

#endif
