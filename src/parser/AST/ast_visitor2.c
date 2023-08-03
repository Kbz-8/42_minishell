/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_visitor2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 11:30:04 by maldavid          #+#    #+#             */
/*   Updated: 2023/08/03 23:15:24 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nexus.h>
#include <ast.h>
#include <memory.h>
#include <stddef.h>
#include <libft.h>
#include <stdint.h>

void	quotes_manager(bool *check_sep, uint8_t *quotes, char c);

static bool	args_splits_is_separator(const char c, const char *charset)
{
	while (*charset++)
		if (*(charset - 1) == c)
			return (true);
	return (false);
}

static int	args_splits_strlen(const char *str, char *sep)
{
	int		length;
	bool	check_sep;
	uint8_t	quotes;

	length = 1;
	check_sep = true;
	quotes = 0;
	while (*str && length)
	{
		quotes_manager(&check_sep, &quotes, *str);
		length++;
		if (check_sep && args_splits_is_separator(*str, sep))
		{
			length--;
			break ;
		}
		str++;
	}
	return (length);
}

static int	args_splits_get_words(const char *str, char *sep)
{
	int		count;
	bool	is_word;
	bool	check_sep;
	uint8_t	quotes;

	count = 0;
	is_word = false;
	check_sep = true;
	quotes = 0;
	while (*str)
	{
		quotes_manager(&check_sep, &quotes, *str);
		if (check_sep && args_splits_is_separator(*str, sep))
			is_word = false;
		else if (!is_word)
		{
			count++;
			is_word = true;
		}
		str++;
	}
	return (count);
}

static char	*args_splits_strdup(const char *str, char *sep)
{
	char	*buf;
	char	*p_buf;
	bool	check_sep;
	char	str_begin;
	uint8_t	quotes;

	buf = (char *)alloc(args_splits_strlen(str, sep) + 1);
	p_buf = buf;
	check_sep = true;
	str_begin = 0;
	quotes = 0;
	while (*str)
	{
		quotes_manager(&check_sep, &quotes, *str);
		if (check_sep && args_splits_is_separator(*str, sep))
			break ;
		if (!quotes)
		{
			*buf = *str;
			buf++;
		}
		str++;
	}
	return (p_buf);
}

char	**args_split(const char *s, char *sep)
{
	char	**tab;
	int		i;
	bool	check_sep;
	bool	is_word;
	uint8_t	quotes;

	i = 0;
	is_word = false;
	tab = (char **)alloc((args_splits_get_words(s, sep) + 1) * sizeof(char *));
	check_sep = true;
	quotes = 0;
	while (*s)
	{
		quotes_manager(&check_sep, &quotes, *s);
		if (check_sep && args_splits_is_separator(*s, sep))
			is_word = false;
		else if (!is_word)
		{
			is_word = true;
			tab[i++] = args_splits_strdup(s, sep);
		}
		s++;
	}
	tab[i] = NULL;
	return (tab);
}
