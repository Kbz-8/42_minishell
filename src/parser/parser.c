/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 01:45:09 by maldavid          #+#    #+#             */
/*   Updated: 2023/01/19 04:40:49 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nexus.h>
#include <stddef.h>
#include <ast.h>

t_parser_info	*parse(const char *entry)
{
	t_ast	*ast;

	if (entry == NULL)
		return (NULL);
	ast = generate_ast(generate_token_list((char *)entry));
	if (ast == NULL)
		return (NULL);
	return (NULL);
}
