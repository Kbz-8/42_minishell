/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:36:03 by maldavid          #+#    #+#             */
/*   Updated: 2022/09/27 15:45:16 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, t_size n)
{
	t_uint8	*ps1;
	t_uint8	*ps2;

	if (!n--)
		return (0);
	ps1 = (t_uint8 *)s1;
	ps2 = (t_uint8 *)s2;
	while (*ps1 && *ps2 && n > 0 && *ps1 == *ps2)
	{
		ps1++;
		ps2++;
		n--;
	}
	return (*ps1 - *ps2);
}
