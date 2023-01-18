/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:37:16 by maldavid          #+#    #+#             */
/*   Updated: 2022/10/12 21:01:08 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	ft_putnbr_fd(long long nb, int fd)
{
	int	is_min_int;
	int	rest;
	int	len;

	len = 0;
	if (nb < 0)
		ft_putchar_fd('-', fd);
	is_min_int = (nb == INT_MIN);
	if (is_min_int)
		nb += 1;
	if (nb < 0)
		len++;
	if (nb < 0)
		nb = ~(nb - 1);
	if (nb > 9)
		len += ft_putnbr_fd(nb / 10, fd);
	rest = nb % 10;
	if (is_min_int)
		rest += 1;
	ft_putchar_fd(rest + '0', fd);
	return (len + 1);
}
