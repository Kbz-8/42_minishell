/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:39:06 by maldavid          #+#    #+#             */
/*   Updated: 2022/10/07 04:00:27 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *str, unsigned int start, t_size len)
{
	char	*sub;

	if (!str)
		return (FT_NULL);
	if (start >= ft_strlen((char *)str))
		return (ft_strdup(""));
	if (start + len > ft_strlen((char *)str))
		len = ft_strlen((char *)str) - start;
	sub = (char *)ft_memalloc(len + 1);
	if (!sub)
		return (FT_NULL);
	ft_memcpy(sub, str + start, len);
	return (sub);
}
