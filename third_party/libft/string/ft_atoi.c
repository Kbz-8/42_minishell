/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:34:03 by maldavid          #+#    #+#             */
/*   Updated: 2022/10/02 04:03:45 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long int	n;
	int			neg;

	n = 0;
	neg = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if ((*str == '+' || *str == '-'))
		if (*str++ == '-')
			neg = ~(neg - 1);
	while (*str >= '0' && *str <= '9')
		n = n * 10 + *str++ - '0';
	if (neg == -1 && n < -2147483648)
		return (0);
	if (neg && n < -2147483648)
		return (-1);
	return (n * neg);
}
