/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:23:06 by maldavid          #+#    #+#             */
/*   Updated: 2023/05/14 11:20:32 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <memory.h>
#include <stdlib.h>
#include <errors.h>
#include <libft.h>

static t_block	**get_blocks(void)
{
	static t_block	*head = NULL;

	return (&head);
}

void	*alloc(size_t size)
{
	t_block	*block;

	block = malloc(size + sizeof(t_block));
	if (block == NULL)
		report(FATAL_ERROR, E_MEMFAIL);
	block->next = *get_blocks();
	block->ptr = (void *)((unsigned long)block + sizeof(t_block));
	*get_blocks() = block;
	return (block->ptr);
}

void	dealloc(void *ptr)
{
	t_block	*buf;
	t_block	*tmp;

	buf = *get_blocks();
	if (buf == NULL)
		return ;
	if (buf->ptr == ptr)
	{
		tmp = buf;
		*get_blocks() = buf->next;
		free(tmp);
		return ;
	}
	while (buf->next != NULL)
	{
		if (buf->next->ptr == ptr)
		{
			tmp = buf->next;
			buf->next = tmp->next;
			free(tmp);
			return ;
		}
		buf = buf->next;
	}
}

void	allfree(void)
{
	t_block	*buf;
	t_block	*dbuf;

	buf = *get_blocks();
	while (buf != NULL)
	{
		dbuf = buf->next;
		free(buf);
		buf = dbuf;
	}
}
