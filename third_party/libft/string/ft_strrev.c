/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 21:35:12 by maldavid          #+#    #+#             */
/*   Updated: 2022/08/02 22:07:08 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrev(char *str)
{
	int	i;
	int	x;

	i = 0;
	x = ft_strlen(str) - 1;
	while (i < x)
	{
		str[i] ^= str[x];
		str[x] ^= str[i];
		str[i++] ^= str[x--];
	}
}
