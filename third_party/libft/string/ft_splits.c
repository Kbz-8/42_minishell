/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:35:09 by maldavid          #+#    #+#             */
/*   Updated: 2023/05/14 11:03:56 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_splits_is_separator(const char c, const char *charset)
{
	while (*charset++)
		if (*(charset - 1) == c)
			return (1);
	return (0);
}

static int	ft_splits_strlen(const char *str, const char *charset)
{
	int	length;

	length = 0;
	while (*str++ && !ft_splits_is_separator(*(str - 1), charset) && ++length)
		;
	return (length);
}

static int	ft_splits_get_words(const char *str, const char *charset)
{
	int	count;
	int	is_word;

	count = 0;
	is_word = 0;
	while (*str++)
	{
		if (ft_splits_is_separator(*(str - 1), charset))
			is_word = 0;
		else
		{
			if (!is_word)
				count++;
			if (!is_word)
				is_word = 1;
		}
	}
	return (count);
}

static char	*ft_splits_strdup(const char *str, const char *charset)
{
	char	*buf;
	char	*p_buf;

	buf = (char *)ft_malloc(ft_splits_strlen(str, charset) + 1);
	if (!buf)
		return (FT_NULL);
	p_buf = buf;
	while (*str && !ft_splits_is_separator(*str, charset))
		*buf++ = *str++;
	*buf = 0;
	return (p_buf);
}

char	**ft_splits(const char *s, const char *charset)
{
	char	**tab;
	int		is_word;
	int		i;

	i = 0;
	is_word = 0;
	tab = (char **)ft_malloc((ft_splits_get_words(s, charset) + 1) * 8);
	if (!tab)
		return (FT_NULL);
	while (*s++)
	{
		if (ft_splits_is_separator(*(s - 1), charset))
			is_word = 0;
		else if (!is_word)
		{
			is_word = 1;
			tab[i] = ft_splits_strdup(s - 1, charset);
			i++;
		}
	}
	tab[i] = 0;
	return (tab);
}
