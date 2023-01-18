/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:45:41 by maldavid          #+#    #+#             */
/*   Updated: 2022/09/28 11:13:32 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*res;
	t_size	s1_len;
	t_size	s2_len;

	if (!s1 || !s2)
		return (FT_NULL);
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	res = (char *)ft_memalloc(s1_len + s2_len + 1);
	if (!res)
		return (FT_NULL);
	ft_memcpy(res, (char *)s1, s1_len);
	ft_memcpy(res + s1_len, (char *)s2, s2_len);
	return (res);
}
