/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 21:54:35 by maldavid          #+#    #+#             */
/*   Updated: 2022/09/28 10:56:20 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int num)
{
	int		i;
	char	*dest;
	long	nb;

	nb = num;
	dest = (char *)ft_memalloc(ft_nbrlen(nb) + 1);
	if (!dest)
		return (FT_NULL);
	if (nb == 0)
	{
		dest[0] = '0';
		return (dest);
	}
	i = ft_nbrlen(nb) - 1;
	if (nb < 0)
		dest[0] = '-';
	if (nb < 0)
		nb = -nb;
	while (nb != 0)
	{
		dest[i--] = nb % 10 + '0';
		nb /= 10;
	}
	return (dest);
}
