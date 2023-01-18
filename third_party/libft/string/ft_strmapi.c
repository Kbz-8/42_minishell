/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:32:05 by maldavid          #+#    #+#             */
/*   Updated: 2022/09/28 11:42:55 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*buf;

	if (!s || !f)
		return (FT_NULL);
	buf = (char *)ft_memalloc(ft_strlen(s) + 1);
	if (!buf)
		return (FT_NULL);
	i = -1;
	while (++i < (int)ft_strlen(s))
		buf[i] = f(i, s[i]);
	return (buf);
}
