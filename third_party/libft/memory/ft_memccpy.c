/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:38:56 by maldavid          #+#    #+#             */
/*   Updated: 2022/09/27 11:33:55 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, t_size n)
{
	t_uint8	*tdst;
	t_uint8	*tsrc;

	tsrc = (t_uint8 *)src;
	tdst = (t_uint8 *)dest;
	while (*tsrc && n--)
	{
		*tdst = *tsrc;
		if (*tdst++ == (t_uint8)c)
			return (tdst);
		tsrc++;
	}
	return (FT_NULL);
}
