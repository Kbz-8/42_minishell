/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sanitizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:28:28 by maldavid          #+#    #+#             */
/*   Updated: 2023/07/21 21:32:03 by maldavid         ###   ########.fr       */
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

/*bool	postprocess_ast_visit(t_parser_info *info)
{

}
*/