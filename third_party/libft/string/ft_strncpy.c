/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:36:08 by maldavid          #+#    #+#             */
/*   Updated: 2023/07/27 02:25:20 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, t_size n)
{
	char	*p_dest;

	p_dest = dest;
	if (src == NULL || dest == NULL)
		return (dest);
	while (*src && n)
	{
		*p_dest++ = *src++;
		n--;
	}
	while (n)
	{
		*p_dest++ = 0;
		n--;
	}
	return (dest);
}
