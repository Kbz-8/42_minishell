/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nlltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 19:58:50 by maldavid          #+#    #+#             */
/*   Updated: 2022/10/12 22:16:06 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strnrev(char *arr, int start, int end)
{
	if (start >= end)
		return ;
	if (*(arr + end) == '\0')
		end--;
	*(arr + start) = *(arr + start) ^ *(arr + end);
	*(arr + end) = *(arr + start) ^ *(arr + end);
	*(arr + start) = *(arr + start) ^ *(arr + end);
	ft_strnrev(arr, start + 1, end - 1);
}

char	*ft_nlltoa(unsigned long long num, char *dest, int pos, int base)
{
	int	i;

	i = pos;
	if (num == 0)
	{
		dest[i] = '0';
		dest[i + 1] = 0;
		return (dest);
	}
	while (num != 0)
	{
		if (num % base > 9)
			dest[i++] = (num % base - 10) + 'a';
		else
			dest[i++] = num % base + '0';
		num /= base;
	}
	ft_strnrev(dest, pos, i - 1);
	return (dest);
}
