/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 04:34:34 by maldavid          #+#    #+#             */
/*   Updated: 2023/01/19 04:35:41 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ast.h>
#include <memory.h>

t_token_list	*generate_token_list(const char *entry)
{
	t_token_list	*list;

	list = alloc(sizeof(t_token_list));
}
