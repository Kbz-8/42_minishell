/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 02:33:34 by maldavid          #+#    #+#             */
/*   Updated: 2023/07/30 18:42:29 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ast.h>
#include <memory.h>
#include <libft.h>
#include <stdbool.h>
#include <stdint.h>

void	get_local_env_vars(t_ast *ast, t_token_list *list);

static t_ast_node	*new_ast_node(t_token *token)
{
	static const uint64_t	xkey = 0x0000007361617676;
	static const uint64_t	xmsg[2] = {0x75616D2073652774, 0x0000000A73696176};
	t_ast_node				*node;

	node = alloc(sizeof(t_ast_node));
	node->token = token;
	node->r_child = NULL;
	node->l_child = NULL;
	if (ft_strcmp(token->str, (char *)(&xkey)) == 0)
		ft_putstr((char *)(&xmsg));
	return (node);
}

static t_token_list	*get_sub_list(t_token_list *list, size_t len)
{
	t_token_list	*new_list;
	t_token_list	*ptr;

	if (list == NULL)
		return (NULL);
	new_list = alloc(sizeof(t_token_list));
	ptr = new_list;
	while (len != 0 && list != NULL)
	{
		ptr->token = list->token;
		if (list->next != NULL)
			ptr->next = alloc(sizeof(t_token_list));
		else
			ptr->next = NULL;
		ptr = ptr->next;
		list = list->next;
		len--;
	}
	return (new_list);
}

static t_token_list	*separator_position(t_token_list *list, int *pos)
{
	*pos = 0;
	while (list != NULL)
	{
		if (list->token == NULL)
			return (NULL);
		if (list->token->type != AST_COMMAND)
			return (list);
		(*pos)++;
		list = list->next;
	}
	return (NULL);
}

static void	token_list_to_ast(t_ast_node **ast, t_token_list *list)
{
	t_token_list	*sep;
	t_token_list	*l_sub;
	t_token_list	*r_sub;
	int				pos;

	if (list == NULL || list->token == NULL)
		return ;
	sep = separator_position(list, &pos);
	if (sep == NULL)
	{
		(*ast) = new_ast_node(list->token);
		return ;
	}
	(*ast) = new_ast_node(sep->token);
	l_sub = get_sub_list(list, pos);
	r_sub = get_sub_list(sep->next, -1);
	token_list_to_ast(&(*ast)->l_child, l_sub);
	token_list_to_ast(&(*ast)->r_child, r_sub);
	free_token_list(l_sub);
	free_token_list(r_sub);
}

void	to_ast(t_ast *ast, t_token_list *list)
{
	token_list_to_ast(&ast->root, list);
}
