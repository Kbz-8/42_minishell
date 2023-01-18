/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:35:02 by maldavid          #+#    #+#             */
/*   Updated: 2022/09/28 11:14:07 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(const char *s, const char sep)
{
	char	**buffer;
	char	temp[2];

	if (!s)
		return (FT_NULL);
	temp[0] = sep;
	temp[1] = 0;
	buffer = ft_splits(s, temp);
	return (buffer);
}
