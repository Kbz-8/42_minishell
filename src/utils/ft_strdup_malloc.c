/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_malloc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 21:22:08 by maldavid          #+#    #+#             */
/*   Updated: 2023/07/30 20:15:06 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <errors.h>
#include <stdlib.h>

char	*ft_strndup_malloc(const char *s, size_t n)
{
	char	*tmp;
	char	*ptr;

	ptr = (char *)malloc(n + 1);
	if (ptr == NULL)
		report(FATAL_ERROR, E_MEMFAIL);
	ft_memset(ptr, 0, n + 1);
	tmp = ptr;
	while (n && *s && tmp)
	{
		*tmp++ = *s++;
		n--;
	}
	return (ptr);
}
