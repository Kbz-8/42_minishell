/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_visitor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:26:28 by maldavid          #+#    #+#             */
/*   Updated: 2023/03/28 18:14:56 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nexus.h>
#include <ast.h>
#include <memory.h>
#include <stddef.h>
#include <libft.h>

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
	t_ast_node		*ptr;
	t_parser_info	*info;

	ptr = ast->root;
	info = alloc(sizeof(t_parser_info));
	ft_memset(info, 0, sizeof(t_parser_info));
	while (ptr != NULL)
	{
		if (ptr->token->type == PIPE)
		{

		}
		ptr = ptr->r_child;
	}
	return (NULL);
}
