/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sanitizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:28:28 by maldavid          #+#    #+#             */
/*   Updated: 2023/07/25 17:18:20 by maldavid         ###   ########.fr       */
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

static void	postpostprocess_ast_visit(t_parser_info *info)
{
	while (info != NULL && info->link != PIPE && info->link != NONE)
	{
		if (info->link == R_IN || info->link == HERE_DOC)
		{
			info->link = info->next->link;
			info->next = info->next->next;
		}
		else
			info = info->next;
	}
}

void	postprocess_ast_visit(t_parser_info *info)
{
	t_parser_info		*tmp;
	t_parser_info		*last;
	enum e_command_link	link;

	last = NULL;
	tmp = info;
	while (tmp->link != PIPE && tmp->link != NONE)
	{
		if (tmp->link == R_IN || tmp->link == HERE_DOC)
			last = tmp;
		tmp = tmp->next;
	}
	if (tmp->link == PIPE)
		postprocess_ast_visit(tmp->next);
	if (last == NULL)
		return;
	tmp = last;
	link = tmp->link;
	last = tmp->next;
	tmp->link = tmp->next->link;
	tmp->next = tmp->next->next;
	last->link = info->link;
	last->next = info->next;
	info->next = last;
	info->link = link;
	postpostprocess_ast_visit(last);
}
