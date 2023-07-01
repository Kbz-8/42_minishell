/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_visitor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:26:28 by maldavid          #+#    #+#             */
/*   Updated: 2023/06/28 18:43:00 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nexus.h>
#include <ast.h>
#include <memory.h>
#include <stddef.h>
#include <libft.h>

static t_parser_info	*visit_command(t_ast_node *node, t_env_var *local_vars)
{
	static const char	*builtins[7] = {"echo", "cd", "pwd", "export", \
										"unset", "env", "exit"};
	int					i;
	t_parser_info		*info;

	info = ft_memalloc(sizeof(t_parser_info));
	info->args = (const char **)args_split(node->token->str, ' ');
	info->local_vars = local_vars;
	i = 0;
	while (i < (int)(sizeof(builtins) / sizeof(builtins[0])))
	{
		if (ft_strcmp(info->args[0], builtins[i]) == 0)
		{
			info->cmd.builtin = i + 1;
			break ;
		}
		i++;
	}
	info->cmd.str = ft_strdup(info->args[0]);
	return (info);
}

static t_parser_info	*visit_pipe(t_ast_node *node, t_env_var *local_vars)
{
	t_parser_info	*info;

	info = visit_command(node->l_child, local_vars);
	info->link = PIPE;
	info->next = visit_ast(node->r_child, local_vars);
	return (info);
}

static t_parser_info	*visit_redirection(t_ast_node *node, t_env_var *local_vars)
{
	t_parser_info	*info;

	info = visit_command(node->l_child, local_vars);
	if (node->token->type == AST_SIMPLE_RED_L)
		info->link = R_IN;
	else if (node->token->type == AST_SIMPLE_RED_R)
		info->link = R_OUT;
	else
		info->link = R_OUT_ABSOLUTE;
	info->next = visit_ast(node->r_child, local_vars);
	return (info);
}

t_parser_info	*visit_ast(t_ast_node *ast, t_env_var *local_vars)
{
	if (ast->token->type == AST_COMMAND)
		return (visit_command(ast, local_vars));
	else if (ast->token->type == AST_PIPE)
		return (visit_pipe(ast, local_vars));
	return (visit_redirection(ast, local_vars));
}
