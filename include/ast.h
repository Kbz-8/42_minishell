/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 02:00:58 by maldavid          #+#    #+#             */
/*   Updated: 2023/05/14 12:27:13 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

# include <nexus.h>
# include <stdbool.h>

enum e_node_type
{
	AST_PIPE = 0,
	AST_SIMPLE_RED_L = 1,
	AST_SIMPLE_RED_R = 2,
	AST_DOUBLE_RED_R = 3,
	AST_HERE_DOC = 4,
	AST_COMMAND = 5,
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
t_parser_info	*visit_ast(t_ast_node *ast);
void			free_token_list(t_token_list *list);
bool			preprocess_ast_visit(t_ast_node *ast);
char			**args_split(const char *s, char sep);

#endif
