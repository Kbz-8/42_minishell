/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:36:12 by maldavid          #+#    #+#             */
/*   Updated: 2022/10/07 00:50:17 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, t_size size)
{
	char	*tmp;
	char	*ptr;

	tmp = (char *)s;
	while (*tmp)
		tmp++;
	ptr = (char *)malloc(size + 1);
	tmp = ptr;
	while (size-- && *s && tmp)
		*tmp++ = *s++;
	if (ptr)
		*tmp = 0;
	return (ptr);
}
