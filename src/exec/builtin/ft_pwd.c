/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 08:24:55 by vvaas             #+#    #+#             */
/*   Updated: 2023/07/26 16:00:32 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <nexus.h>
#include <libft.h>
#include <unistd.h>

int	ft_pwd(void)
{
	char *buf;

	buf = (char *)getcwd(NULL, 0);
	ft_putstr(buf);
	free(buf);
	ft_putchar('\n');
	get_env_data()->last_return = 0;
	return (0);
}
