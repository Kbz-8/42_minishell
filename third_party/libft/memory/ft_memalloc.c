/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:51:15 by maldavid          #+#    #+#             */
/*   Updated: 2023/05/14 11:10:54 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_set_internal_malloc(t_alloc f)
{
	*ft_get_internal_alloc() = f;
}

t_alloc	*ft_get_internal_alloc(void)
{
	static t_alloc	_alloc = malloc;

	return (&_alloc);
}

void	*ft_malloc(t_size size)
{
	return ((*ft_get_internal_alloc())(size));
}

void	*ft_memalloc(t_size size)
{
	void	*ptr;

	ptr = ft_malloc(size);
	if (!ptr)
		return (FT_NULL);
	ft_memset(ptr, 0, size);
	return (ptr);
}
