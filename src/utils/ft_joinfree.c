/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinfree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:26:53 by vvaas             #+#    #+#             */
/*   Updated: 2023/05/14 12:15:10 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <memory.h>

char	*ft_joinfree(char *dest, char *src)
{
	char	*tmp;

	if (dest == NULL)
		dest = (char *)ft_calloc(1, 1);
	tmp = ft_strjoin(dest, src);
	ft_free(dest);
	return (tmp);
}
