/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:51:15 by maldavid          #+#    #+#             */
/*   Updated: 2022/09/27 11:34:02 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(t_size size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		return (FT_NULL);
	ft_memset(ptr, 0, size);
	return (ptr);
}
