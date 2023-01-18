/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:26:36 by maldavid          #+#    #+#             */
/*   Updated: 2022/09/29 12:51:37 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	beg;
	int	end;

	if (!s1)
		return (FT_NULL);
	if (!set)
		return (ft_strdup((char *)s1));
	beg = 0;
	end = ft_strlen(s1);
	while (s1[beg] && ft_strchr(set, s1[beg]))
		beg++;
	while (s1[end - 1] && ft_strchr(set, s1[end - 1]) && end > beg)
		end--;
	return (ft_substr((char *)s1, beg, end - beg));
}
