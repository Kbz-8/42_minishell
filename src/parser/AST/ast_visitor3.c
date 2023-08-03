/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_visitor3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 22:59:35 by maldavid          #+#    #+#             */
/*   Updated: 2023/08/03 23:10:04 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nexus.h>
#include <ast.h>
#include <memory.h>
#include <stddef.h>
#include <libft.h>
#include <stdint.h>

void	quotes_manager(bool *check_sep, uint8_t *quotes, char c)
{
	if (c == '"' && (*quotes & 0x0F) && (*quotes & 0xF0) == 0)
		*quotes = 0;
	else if (c == '\'' && (*quotes & 0xF0) && (*quotes & 0x0F) == 0)
		*quotes = 0;
	if (*quotes == 0)
		*check_sep = true;
	else
		*check_sep = false;
}
