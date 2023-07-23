/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sanitizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:28:28 by maldavid          #+#    #+#             */
/*   Updated: 2023/07/23 21:10:32 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ast.h>
#include <nexus.h>
#include <memory.h>
#include <errors.h>
#include <stdbool.h>
#include <libft.h>

static bool	something_went_wrong(int error_code)
{
	report(ERROR, error_code);
	return (false);
}

bool	preprocess_ast_visit(t_ast_node *ast)
{
	if (ast == NULL)
		return (true);
	if (ast->token->type != AST_COMMAND && ast->l_child == NULL)
		return (something_went_wrong(E_SANITIZE_NEAR));
	return (preprocess_ast_visit(ast->r_child));
}

void	postprocess_ast_visit(t_parser_info *info)
{
	t_parser_info	*tmp;
	t_parser_info	*last_r_in;

	last_r_in = NULL;
	tmp = info;
	while (tmp->link != PIPE && tmp->link != NONE)
	{
		if (tmp->link == R_IN)
			last_r_in = tmp;
		tmp = tmp->next;
	}
	if (tmp->link == PIPE)
		postprocess_ast_visit(tmp->next);
	if (last_r_in != NULL)
	{
		tmp = last_r_in;
		last_r_in = tmp->next;
		tmp->link = tmp->next->link;
		tmp->next = tmp->next->next;
		last_r_in->link = info->link;
		last_r_in->next = info->next;
		info->next = last_r_in;
		info->link = R_IN;
	}
}
