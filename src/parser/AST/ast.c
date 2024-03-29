/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 02:07:39 by maldavid          #+#    #+#             */
/*   Updated: 2023/08/03 21:01:41 by maldavid         ###   ########.fr       */
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
	ast->local_vars = NULL;
	token_list_to_ast(&ast->root, list);
	free_token_list(list);
	return (ast);
}
