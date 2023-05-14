/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:44:48 by maldavid          #+#    #+#             */
/*   Updated: 2023/05/14 11:03:20 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, int n)
{
	int		i;
	int		j;
	char	*str;

	str = (char *)ft_malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j] && n != 0)
	{
		str[i + j] = s2[j];
		n--;
		j++;
	}
	str[i + j] = 0;
	ft_free((char *)s1);
	return (str);
}
