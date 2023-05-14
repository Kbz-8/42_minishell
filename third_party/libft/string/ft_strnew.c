/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:56:27 by maldavid          #+#    #+#             */
/*   Updated: 2023/05/14 11:05:32 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(t_size size)
{
	char	*str;

	str = (char *)ft_malloc(size + 1);
	if (!str)
		return (FT_NULL);
	ft_memset(str, 0, size + 1);
	return (str);
}
