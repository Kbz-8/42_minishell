/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 02:07:39 by maldavid          #+#    #+#             */
/*   Updated: 2023/01/21 12:44:06 by maldavid         ###   ########.fr       */
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
	return (ast);
}
