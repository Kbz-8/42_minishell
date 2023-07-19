/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 21:38:21 by maldavid          #+#    #+#             */
/*   Updated: 2023/07/19 13:50:04 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *buf, int c, t_size n)
{
	t_uint8	*tmp;

	tmp = (t_uint8 *)buf;
	while (n--)
	{
		if (*tmp == (t_uint8)c)
			return (tmp);
		tmp++;
	}
	return (FT_NULL);
}
