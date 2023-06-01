/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 01:45:09 by maldavid          #+#    #+#             */
/*   Updated: 2023/06/01 20:22:58 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nexus.h>
#include <stddef.h>
#include <ast.h>
#include <libft.h>

t_parser_info	*parse(const char *entry)
{
	t_ast	*ast;

	if (entry == NULL)
		return (NULL);
	ast = generate_ast(generate_token_list((char *)entry));
	if (ast == NULL || !preprocess_ast_visit(ast->root))
		return (NULL);
	return (visit_ast(ast->root));
}
