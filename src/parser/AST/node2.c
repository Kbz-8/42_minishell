/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:33:00 by maldavid          #+#    #+#             */
/*   Updated: 2023/02/13 11:44:50 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ast.h>

void	add_leaves(t_ast *ast)
{
	t_ast_node		*ptr;
	t_token_list	*token;

	ptr = ast->root;
	if (ptr == NULL)
		return ;
	while (ptr != NULL || ptr == ast->root)
	{
		token = ptr->token;
		ptr = ptr->r_child;
	}
}
