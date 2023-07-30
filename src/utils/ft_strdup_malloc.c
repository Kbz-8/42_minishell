/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_malloc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 21:22:08 by maldavid          #+#    #+#             */
/*   Updated: 2023/07/30 19:24:06 by maldavid         ###   ########.fr       */
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

char	*ft_strjoin_malloc(char const *s1, char const *s2)
{
	unsigned int	i;
	char			*new_str;
	int				buffer_size;
	unsigned int	j;

	j = 0;
	if (!s1 || !s2)
		return (NULL);
	buffer_size = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	new_str = malloc(buffer_size);
	if (!new_str)
		return (NULL);
	ft_memset(new_str, 0, buffer_size);
	i = 0;
	while (s1[j])
		new_str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		new_str[i++] = s2[j++];
	return (new_str);
}
