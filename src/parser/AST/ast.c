/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 02:07:39 by maldavid          #+#    #+#             */
/*   Updated: 2023/02/08 18:19:13 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ast.h>
#include <memory.h>
#include <libft.h>
#include <stdbool.h>
#include <errors.h>

bool	sanitize_token_list(t_token_list *list)
{
	if (list->token->type == PIPE)
	{
		report(ERROR, E_PIPES);
		return (false);
	}
	while (list != NULL)
	{
		if (list->token->type == PIPE && list->prev->token->type == PIPE)
		{
			report(ERROR, E_PIPES);
			return (false);
		}
		list = list->next;
	}
	return (true);
}

void print_token(t_token_list *token)
{
	if (token->token->type == PIPE)
		ft_putstr("|\n");
	else if (token->token->type == SIMPLE_RED_L)
		ft_putstr("<\n");
	else if (token->token->type == SIMPLE_RED_R)
		ft_putstr(">\n");
	else if (token->token->type == DOUBLE_RED_R)
		ft_putstr(">>\n");
	else
		ft_printf("token %s\n", token->token->str);
}

t_ast	*generate_ast(t_token_list *list)
{
	t_ast	*ast;

	if (list == NULL)
		return (NULL);
	ast = alloc(sizeof(t_ast));
	ast->root = NULL;
	if (!sanitize_token_list(list))
		return (NULL);
	add_pipes(ast, list);
	add_redirections(ast);
	print_token(ast->root->token);
	/*
	print_token(ast->root->l_child->token);
	print_token(ast->root->r_child->token);
	*/
	return (ast);
}
