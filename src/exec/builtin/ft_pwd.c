/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 08:24:55 by vvaas             #+#    #+#             */
/*   Updated: 2023/07/13 15:51:01 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <nexus.h>
#include <libft.h>
#include <errors.h>

int	ft_pwd(void)
{
	ft_putstr((char *)get_env_var("PWD"));
	ft_putchar('\n');
	get_env_data()->last_return = 0;
	return (0);
}