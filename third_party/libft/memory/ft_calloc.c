/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:13:44 by maldavid          #+#    #+#             */
/*   Updated: 2023/05/14 11:10:51 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_set_internal_free(t_free f)
{
	*ft_get_internal_free() = f;
}

t_free	*ft_get_internal_free(void)
{
	static t_free	_free = free;

	return (&_free);
}

void	ft_free(void *ptr)
{
	return ((*ft_get_internal_free())(ptr));
}

void	*ft_calloc(t_size n, t_size size)
{
	void	*ptr;

	if (n * size > 0xFFFFFFFFUL || n >= 0xFFFFFFFFUL || size >= 0xFFFFFFFFUL)
		return (FT_NULL);
	ptr = ft_malloc(n * size);
	if (!ptr)
		return (FT_NULL);
	ft_bzero(ptr, size * n);
	return (ptr);
}
