/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_malloc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 21:22:08 by maldavid          #+#    #+#             */
/*   Updated: 2023/07/25 21:32:42 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strndup_malloc(const char *s, size_t n)
{
	char	*tmp;
	char	*ptr;

	ptr = (char *)malloc(n + 1);
	tmp = ptr;
	while (n && *s && tmp)
	{
		*tmp++ = *s++;
		n--;
	}
	if (ptr)
		*tmp = 0;
	return (ptr);
}
