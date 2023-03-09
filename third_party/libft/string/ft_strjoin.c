/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:45:41 by maldavid          #+#    #+#             */
/*   Updated: 2023/03/09 18:08:38 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	char			*new_str;
	int				buffer_size;
	unsigned int	j;

	j = 0;
	if (!s1 || !s2)
		return ((void *)0);
	buffer_size = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	new_str = (char *)ft_calloc(1, buffer_size);
	if (!new_str)
		return (NULL);
	i = 0;
	while (s1[j])
		new_str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		new_str[i++] = s2[j++];
	return (new_str);
}
