/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:25:19 by vvaas             #+#    #+#             */
/*   Updated: 2023/02/10 17:38:35 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nexus.h>
#include <libft.h>
#include <stdio.h>
#include <stdbool.h>

void	ft_echo(const char *args)
{
	bool newline;
	unsigned int i;

	i = 4; // enlever une fois parser fini
	newline = 1;
	while (args[i] == ' ')
		i++;
	if (ft_strncmp(&args[i], "-n", 2) == 0)
	{
		newline = 0;
		i += 2;
	}
	while (args[i] == ' ')
		i++;
	while (args[i])
	{
		if (ft_strncmp(&args[i], "$?", 2) == 0)
			{} // appeller fct postprocess
		else
			printf("%c", args[i]);
		i++;
	}
	if (newline)
		printf("\n");
}