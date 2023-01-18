/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:10:27 by maldavid          #+#    #+#             */
/*   Updated: 2023/01/18 11:44:15 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <user_input.h>
#include <libft.h>
#include <memory.h>

int	main(int ac, char **av)
{
	char *pouic = user_input();
	(void)ac;
	(void)av;
	ft_printf("%s\n", pouic);
	allfree();
	return (0);
}
