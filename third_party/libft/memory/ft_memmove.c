/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 17:39:00 by maldavid          #+#    #+#             */
/*   Updated: 2022/09/27 17:26:44 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, t_size n)
{
	t_uint8	*pdst;
	t_uint8	*psrc;

	if (!dest && !src)
		return (FT_NULL);
	pdst = (t_uint8 *)dest;
	psrc = (t_uint8 *)src;
	if (psrc < pdst)
	{
		pdst += n;
		psrc += n;
		while (n--)
			*--pdst = *--psrc;
	}
	else
		while (n--)
			*pdst++ = *psrc++;
	return (dest);
}
