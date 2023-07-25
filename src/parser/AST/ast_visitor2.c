/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_visitor2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 11:30:04 by maldavid          #+#    #+#             */
/*   Updated: 2023/07/25 20:37:05 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nexus.h>
#include <ast.h>
#include <memory.h>
#include <stddef.h>
#include <libft.h>

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

	length = 1;
	check_sep = true;
	while (*str && length)
	{
		if (*str == '"' || *str == '\'')
			check_sep = !check_sep;
		else
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
	int		is_word;
	bool	check_sep;

	count = 0;
	is_word = 0;
	check_sep = true;
	while (*str)
	{
		if (*str == '"' || *str == '\'')
			check_sep = !check_sep;
		if (check_sep && args_splits_is_separator(*str, sep))
			is_word = 0;
		else if (!is_word)
		{
			count++;
			is_word = 1;
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

	buf = (char *)alloc(args_splits_strlen(str, sep) + 1);
	p_buf = buf;
	check_sep = true;
	while (*str)
	{
		if (*str == '"' || *str == '\'')
			check_sep = !check_sep;
		if (check_sep && args_splits_is_separator(*str, sep))
			break ;
		if (*str != '"' && *str != '\'')
		{
			*buf = *str;
			buf++;
		}
		str++;
	}
	*buf = 0;
	return (p_buf);
}

char	**args_split(const char *s, char *sep)
{
	char	**tab;
	int		is_word;
	int		i;
	bool	check_sep;

	i = 0;
	is_word = 0;
	tab = (char **)alloc((args_splits_get_words(s, sep) + 1) * sizeof(char *));
	check_sep = true;
	while (*s)
	{
		if (*s == '"' || *s == '\'')
			check_sep = !check_sep;
		if (check_sep && args_splits_is_separator(*s, sep))
			is_word = 0;
		else if (!is_word)
		{
			is_word = 1;
			tab[i] = args_splits_strdup(s, sep);
			i++;
		}
		s++;
	}
	tab[i] = NULL;
	return (tab);
}
