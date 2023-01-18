/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:23:06 by maldavid          #+#    #+#             */
/*   Updated: 2023/01/18 11:36:56 by maldavid         ###   ########.fr       */
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
		report(E_MEMFAIL);
	ft_lstadd_front(get_blocks(), ft_lstnew(ptr));
	return (ptr);
}

void	dealloc(void *ptr)
{
	t_list	*buf;

	buf = *get_blocks();
	(void)ptr;
}

void	allfree(void)
{
	ft_lstclear(get_blocks(), free);
}
