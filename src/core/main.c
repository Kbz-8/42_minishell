/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:10:27 by maldavid          #+#    #+#             */
/*   Updated: 2023/01/18 11:34:51 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <user_input.h>
#include <libft.h>

int	main(int ac, char **av)
{
	char *pouic = user_input();
	(void)ac;
	(void)av;
	ft_printf("%s", pouic);
	free(pouic);
	return (0);
}
