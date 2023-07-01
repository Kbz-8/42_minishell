/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:50:40 by maldavid          #+#    #+#             */
/*   Updated: 2023/06/28 18:57:05 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ast.h>
#include <nexus.h>
#include <libft.h>
#include <memory.h>
#include <stddef.h>

void	get_local_env_vars(t_ast *ast, t_token_list *list)
{
	char	*key;
	char	*value;
	char	*str;
	char	*found;
	t_env_var	*new;

	if (list->token->type == AST_COMMAND)
	{
		str = list->token->str;
		found = ft_strchr(str, '=');
		while (found != NULL)
		{
			value = ft_strndup(found + 1, \
							(t_size)(ft_strchr(found, ' ') - found + 1));
			key = ft_strndup(str, (t_size)(found - str));
			new = alloc(sizeof(t_env_var));
			new->key = ft_strdup(key);
			new->value = ft_strdup(value);
			new->next = ast->local_vars;
			ast->local_vars = new;
			list->token->str = ft_strchr(found, ' ');
			found = ft_strchr(found + 1, '=');
		}
	}
	if (list->next != NULL)
		get_local_env_vars(ast, list->next);
}
