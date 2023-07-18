/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 08:24:55 by vvaas             #+#    #+#             */
/*   Updated: 2023/07/18 22:55:16 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <nexus.h>
#include <libft.h>
#include <unistd.h>
int	ft_pwd(void)
{
	ft_putstr((char *)getcwd(NULL, 0));
	ft_putchar('\n');
	get_env_data()->last_return = 0;
	return (0);
}