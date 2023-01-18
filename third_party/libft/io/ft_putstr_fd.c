/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:37:27 by maldavid          #+#    #+#             */
/*   Updated: 2022/10/12 20:34:53 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	ft_putstr_fd(char *s, int fd)
{
	if (fd < 0)
		return (0);
	if (!s)
		return (ft_putstr_fd("(null)", fd));
	write(fd, s, ft_strlen(s));
	return ((int)ft_strlen(s));
}
