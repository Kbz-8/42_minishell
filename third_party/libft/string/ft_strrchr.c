/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:36:17 by maldavid          #+#    #+#             */
/*   Updated: 2022/10/07 04:04:23 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	t_size	i;

	while (c > 255)
		c -= 256;
	i = ft_strlen(s) + 1;
	while (i--)
		if (s[i] == c)
			return ((char *)s + i);
	return (FT_NULL);
}
