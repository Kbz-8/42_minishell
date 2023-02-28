/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 02:07:39 by maldavid          #+#    #+#             */
/*   Updated: 2023/02/28 15:53:58 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ast.h>
#include <memory.h>
#include <libft.h>
#include <stdbool.h>
#include <errors.h>

bool	sanitize_token_list(t_token_list *list)
{
	if (list->token->type == PIPE)
	{
		report(ERROR, E_PIPES);
		return (false);
	}
	while (list != NULL)
	{
		if (list->token->type == PIPE && list->prev->token->type == PIPE)
		{
			report(ERROR, E_PIPES);
			return (false);
		}
		list = list->next;
	}
	return (true);
}

#include <stdio.h>
static char buffer[1024];

static void print_subtree(t_ast_node* n, const char *prf_right, const char *prf_left, char *buf, int buf_sz)
{
    if (n->r_child)
	{
        int res = snprintf(buf, buf_sz, "%s", prf_right);
        print_subtree(n->r_child, "     ", "|    ", buf + res, buf_sz - res);
        *buf = '\0';
    }
    ft_printf("%s+---'%s'\n", buffer, n->token->str);
    if (n->l_child)
	{
        int res = snprintf(buf, buf_sz, "%s", prf_left);
        print_subtree(n->l_child, "|    ", "     ", buf + res, buf_sz - res);
        *buf = '\0';
    }
}

t_ast	*generate_ast(t_token_list *list)
{
	t_ast	*ast;

	if (list == NULL || !sanitize_token_list(list))
		return (NULL);
	ast = alloc(sizeof(t_ast));
	ast->root = NULL;
	to_ast(ast, list);
	print_subtree(ast->root, "     ", "     ", buffer, sizeof(buffer));
	return (ast);
}
