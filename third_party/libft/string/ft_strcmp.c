/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroussar <contact@xtrm.me>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 08:20:14 by kroussar          #+#    #+#             */
/*   Updated: 2022/09/28 10:59:17 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	t_uint8	*ps1;
	t_uint8	*ps2;

	ps1 = (t_uint8 *)s1;
	ps2 = (t_uint8 *)s2;
	while (*ps1 == *ps2 && *ps1)
	{
		ps1++;
		ps2++;
	}
	return (*ps1 - *ps2);
}
