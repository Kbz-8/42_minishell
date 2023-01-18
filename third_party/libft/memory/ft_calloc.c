/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:13:44 by maldavid          #+#    #+#             */
/*   Updated: 2022/10/07 02:19:38 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(t_size n, t_size size)
{
	void	*ptr;

	if (n * size > 0xFFFFFFFFUL || n >= 0xFFFFFFFFUL || size >= 0xFFFFFFFFUL)
		return (FT_NULL);
	ptr = malloc(n * size);
	if (!ptr)
		return (FT_NULL);
	ft_bzero(ptr, size * n);
	return (ptr);
}
