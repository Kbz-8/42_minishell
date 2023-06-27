/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:50:40 by maldavid          #+#    #+#             */
/*   Updated: 2023/06/27 21:24:54 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ast.h>
#include <nexus.h>
#include <stddef.h>

void	get_local_env_vars(t_ast *ast, t_token_list *list)
{
	size_t	i;

	i = 0;
	if (list->token->type == AST_COMMAND)
	{
		while (list->token->str[i] != 0)
		{
			i++;
		}
	}
	if (list->next != NULL)
		get_local_env_vars(ast, list->next);
}
