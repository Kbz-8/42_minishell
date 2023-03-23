/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_visitor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:26:28 by maldavid          #+#    #+#             */
/*   Updated: 2023/03/23 10:21:55 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nexus.h>
#include <ast.h>
#include <stddef.h>

t_parser_info	*visit_pipe(t_ast_node *node)
{
	(void)node;
	return (NULL);
}

t_parser_info	*visit_redirection(t_ast_node *node)
{
	(void)node;
	return (NULL);
}

t_parser_info	*visit_command(t_ast_node *node)
{
	(void)node;
	return (NULL);
}

t_parser_info	*visit_ast(t_ast *ast)
{
	(void)ast;
	return (NULL);
}
