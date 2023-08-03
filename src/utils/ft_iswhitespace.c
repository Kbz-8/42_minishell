/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswhitespace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 19:05:42 by vvaas             #+#    #+#             */
/*   Updated: 2023/08/03 19:43:44 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <libft.h>

bool	ft_iswhitespace(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (true);
	if (ft_strlen(str) == 0)
		return (true);
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	return ((int)ft_strlen(str) == i);
}
