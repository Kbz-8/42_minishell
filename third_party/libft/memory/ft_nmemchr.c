/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nmemchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 12:26:06 by maldavid          #+#    #+#             */
/*   Updated: 2022/12/28 12:26:44 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_nmemchr(const void *buf, int c, t_size n)
{
	t_uint8	*tmp;

	tmp = (t_uint8 *)buf;
	while (n--)
	{
		if (*tmp != (t_uint8)c)
			return (tmp);
		tmp++;
	}
	return (FT_NULL);
}
