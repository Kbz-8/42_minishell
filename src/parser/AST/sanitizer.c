/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sanitizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:28:28 by maldavid          #+#    #+#             */
/*   Updated: 2023/07/26 16:27:30 by maldavid         ###   ########.fr       */
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
	if ((ast->token->type == AST_PIPE || ast->token->type == AST_SIMPLE_RED_L) \
		   	&& ast->l_child == NULL)
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
	t_parser_info		*tmp[2];
	enum e_command_link	link;

	tmp[1] = NULL;
	tmp[0] = info;
	while (tmp[0]->link != PIPE && tmp[0]->link != NONE)
	{
		if (tmp[0]->link == R_IN || tmp[0]->link == HERE_DOC)
			tmp[1] = tmp[0];
		tmp[0] = tmp[0]->next;
	}
	if (tmp[0]->link == PIPE)
		postprocess_ast_visit(tmp[0]->next);
	if (tmp[1] == NULL)
		return ;
	tmp[0] = tmp[1];
	link = tmp[0]->link;
	tmp[1] = tmp[0]->next;
	tmp[0]->link = tmp[0]->next->link;
	tmp[0]->next = tmp[0]->next->next;
	tmp[1]->link = info->link;
	tmp[1]->next = info->next;
	info->next = tmp[1];
	info->link = link;
	postpostprocess_ast_visit(tmp[1]);
}
