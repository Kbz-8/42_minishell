/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:48:32 by maldavid          #+#    #+#             */
/*   Updated: 2022/10/07 04:11:24 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, t_size n)
{
	t_size	i;
	t_size	j;
	t_size	to_find_size;

	if (*needle == 0 || (!haystack && n == 0))
		return ((char *)haystack);
	i = 0;
	j = 0;
	to_find_size = ft_strlen(needle);
	if (to_find_size == 0)
		return ((char *)haystack);
	while (haystack[i] && n--)
	{
		while (needle[j] == haystack[i + j])
		{
			if (j > n)
				return (FT_NULL);
			if (j == to_find_size - 1)
				return ((char *)(haystack + i));
			j++;
		}
		j = 0;
		i++;
	}
	return (FT_NULL);
}
