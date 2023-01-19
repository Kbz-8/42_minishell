/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:23:06 by maldavid          #+#    #+#             */
/*   Updated: 2023/01/19 10:40:56 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <memory.h>
#include <stdlib.h>
#include <errors.h>
#include <libft.h>

static t_list	**get_blocks(void)
{
	static t_list	*head = NULL;

	return (&head);
}

void	*alloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		report(FATAL_ERROR, E_MEMFAIL);
	ft_lstadd_front(get_blocks(), ft_lstnew(ptr));
	return (ptr);
}

void	*kalloc(size_t n, size_t size)
{
	void	*ptr;

	if (n * size > 0xFFFFFFFFUL || n >= 0xFFFFFFFFUL || size >= 0xFFFFFFFFUL)
		return (NULL);
	ptr = alloc(n * size);
	ft_bzero(ptr, size * n);
	return (ptr);
}

void	dealloc(void *ptr)
{
	t_list	*buf;
	t_list	*tmp;

	buf = *get_blocks();
	if (buf == NULL)
		return ;
	if (buf->content == ptr)
	{
		tmp = buf;
		buf = buf->next;
		ft_lstdelone(tmp, free);
	}
	while (buf->next != NULL)
	{
		if (buf->next->content == ptr)
		{
			tmp = buf->next;
			buf->next = tmp->next;
			ft_lstdelone(tmp, free);
			return ;
		}
		buf = buf->next;
	}
}

void	allfree(void)
{
	ft_lstclear(get_blocks(), free);
}
