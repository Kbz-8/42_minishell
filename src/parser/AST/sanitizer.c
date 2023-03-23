/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sanitizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:28:28 by maldavid          #+#    #+#             */
/*   Updated: 2023/03/23 12:19:56 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ast.h>
#include <nexus.h>
#include <memory.h>
#include <errors.h>
#include <stdbool.h>

static	bool something_went_wrong(int error_code)
{
	report(ERROR, error_code);
	return false;
}

bool	preprocess_ast_visit(t_ast *ast)
{
	t_ast_node	*ptr;

	ptr = ast->root;
	while (ptr != NULL)
	{
		if (ptr->token->type == PIPE && (ptr->l_child == NULL || ptr->r_child == NULL))
			return (something_went_wrong(E_PIPES));
		ptr = ptr->r_child;
	}
	return (true);
}
