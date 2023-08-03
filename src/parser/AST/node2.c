/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:49:15 by maldavid          #+#    #+#             */
/*   Updated: 2023/08/03 19:07:50 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ast.h>
#include <memory.h>
#include <libft.h>
#include <stdbool.h>
#include <stdint.h>

static int	skip(char *str, int start, bool spaces)
{
	int	i;

	i = start;
	while (str[i])
	{
		if (spaces && !ft_isspace(str[i]))
			return (i);
		if (!spaces && ft_isspace(str[i]))
			return (i);
		i++;
	}
	return (i);
}

void	redirections_sanitize(t_ast_node *ast)
{
	char	**split;
	char	**str;
	int		i;

	if (ast->r_child->token->type != AST_COMMAND)
		split = args_split(ast->r_child->l_child->token->str, " \t");
	else
		split = args_split(ast->r_child->token->str, " \t");
	if (split[1] == NULL)
		return ;
	str = &ast->r_child->token->str;
	i = skip(*str, skip(*str, skip(*str, 0, true), false), true);
	(*str)[i - 1] = 0;
	if (ast->l_child == NULL)
		ast->l_child = new_ast_node(new_token(ft_strdup((*str) + i))->token);
	else
	{
		split = &ast->l_child->token->str;
		*split = ft_strjoin(*split, " ");
		*split = ft_strjoin(*split, (*str) + i);
	}
}
