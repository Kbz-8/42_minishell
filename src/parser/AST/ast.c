/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 02:07:39 by maldavid          #+#    #+#             */
/*   Updated: 2023/05/14 13:12:30 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ast.h>
#include <memory.h>
#include <libft.h>
#include <stdbool.h>
#include <errors.h>

t_ast	*generate_ast(t_token_list *list)
{
	t_ast	*ast;

	if (list == NULL)
		return (NULL);
	ast = alloc(sizeof(t_ast));
	ast->root = NULL;
	to_ast(ast, list);
	free_token_list(list);
	return (ast);
}
