/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:36:33 by maldavid          #+#    #+#             */
/*   Updated: 2022/09/27 12:59:42 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	j;
	int	to_find_size;

	i = 0;
	j = 0;
	to_find_size = 0;
	while (needle[to_find_size])
		to_find_size++;
	if (to_find_size == 0)
		return ((char *)haystack);
	while (haystack[i])
	{
		while (needle[j] == haystack[i + j])
		{
			if (j == to_find_size - 1)
				return ((char *)(haystack + i));
			j++;
		}
		j = 0;
		i++;
	}
	return (FT_NULL);
}
