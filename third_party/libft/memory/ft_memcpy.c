/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:46:30 by maldavid          #+#    #+#             */
/*   Updated: 2023/01/19 06:36:08 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy_raw(void *dest, const void *src, t_size size)
{
	t_uint8	*p_dest;
	t_uint8	*p_src;

	if (!dest && !src)
		return (FT_NULL);
	p_dest = (t_uint8 *)dest;
	p_src = (t_uint8 *)src;
	while (size--)
		*p_dest++ = *p_src++;
	return (dest);
}

void	*ft_memcpy_64(void *dest, const void *src, t_size size)
{
	t_uint64	*p_dest;
	t_uint64	*p_src;

	if (!dest && !src)
		return (FT_NULL);
	p_dest = (t_uint64 *)dest;
	p_src = (t_uint64 *)src;
	while (size)
	{
		*p_dest++ = *p_src++;
		size -= sizeof(t_uint64);
	}
	return (dest);
}

void	*ft_memcpy_32(void *dest, const void *src, t_size size)
{
	t_uint32	*p_dest;
	t_uint32	*p_src;

	if (!dest && !src)
		return (FT_NULL);
	p_dest = (t_uint32 *)dest;
	p_src = (t_uint32 *)src;
	while (size)
	{
		*p_dest++ = *p_src++;
		size -= sizeof(t_uint32);
	}
	return (dest);
}

void	*ft_memcpy_16(void *dest, const void *src, t_size size)
{
	t_uint16	*p_dest;
	t_uint16	*p_src;

	if (!dest && !src)
		return (FT_NULL);
	p_dest = (t_uint16 *)dest;
	p_src = (t_uint16 *)src;
	while (size)
	{
		*p_dest++ = *p_src++;
		size -= sizeof(t_uint16);
	}
	return (dest);
}

void	*ft_memcpy(void *dest, const void *src, t_size size)
{
	if (size % sizeof(t_uint64) == 0)
		return (ft_memcpy_64(dest, src, size));
	if (size % sizeof(t_uint32) == 0)
		return (ft_memcpy_32(dest, src, size));
	if (size % sizeof(t_uint16) == 0)
		return (ft_memcpy_16(dest, src, size));
	return (ft_memcpy_raw(dest, src, size));
}
