/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 21:32:45 by vvaas             #+#    #+#             */
/*   Updated: 2023/07/28 21:40:34 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nexus.h>
#include <libft.h>
#include <stddef.h>

bool	key_exists(char *key)
{
	t_env_var	*ptr;

	ptr = get_env_data()->vars;
	if (ptr == NULL)
		return (false);
	while (ptr->next != NULL)
	{
		if (ft_strcmp(key, ptr->key) == 0)
			return (true);
		ptr = ptr->next;
	}
	return (false);
}
