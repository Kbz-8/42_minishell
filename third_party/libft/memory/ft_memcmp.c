/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:42:14 by maldavid          #+#    #+#             */
/*   Updated: 2022/09/27 11:33:45 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, t_size n)
{
	t_uint8	*ts1;
	t_uint8	*ts2;

	if (!n)
		return (0);
	ts1 = (t_uint8 *)s1;
	ts2 = (t_uint8 *)s2;
	while (--n && *ts1 == *ts2)
	{
		ts1++;
		ts2++;
	}
	return (*ts1 - *ts2);
}
