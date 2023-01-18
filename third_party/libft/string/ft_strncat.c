/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:35:58 by maldavid          #+#    #+#             */
/*   Updated: 2022/09/20 14:35:59 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, t_size n)
{
	char	*p_dest;

	p_dest = dest + ft_strlen(dest);
	while (n-- && *src)
		*p_dest++ = *src++;
	*p_dest++ = '\0';
	return (dest);
}
