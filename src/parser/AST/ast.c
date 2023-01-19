/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 02:07:39 by maldavid          #+#    #+#             */
/*   Updated: 2023/01/19 07:24:09 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ast.h>
#include <memory.h>
#include <libft.h>

t_ast		*generate_ast(t_token_list *list)
{
	t_ast	*ast;

	ast = alloc(sizeof(t_ast));
	while (list != NULL)
	{
		if (list->type == PIPE)
			ft_printf("pipe : %s\n", list->str);
		else if (list->type == COMMAND)
			ft_printf("cmd  : %s\n", list->str);
		else if (list->type == DOUBLE_RED_L)
			ft_printf("rdl  : %s\n", list->str);
		else if (list->type == DOUBLE_RED_R)
			ft_printf("rdr  : %s\n", list->str);
		else if (list->type == SIMPLE_RED_L)
			ft_printf("rsl  : %s\n", list->str);
		else if (list->type == SIMPLE_RED_R)
			ft_printf("rsr  : %s\n", list->str);
		list = list->next;
	}
	return (ast);
}
