/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:35:43 by maldavid          #+#    #+#             */
/*   Updated: 2022/09/27 18:04:19 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_size	ft_strlcat(char *dest, const char *src, t_size size)
{
	t_size	length;

	if (size == 0)
		return (ft_strlen(src));
	length = ft_strlen(dest);
	if (length >= size)
		length = size;
	if (length == size)
		return (length + ft_strlen(src));
	return (length + ft_strlcpy(dest + length, src, size - length));
}
