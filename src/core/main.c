/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:10:27 by maldavid          #+#    #+#             */
/*   Updated: 2023/01/19 05:25:28 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <user_input.h>
#include <libft.h>
#include <memory.h>
#include <stdio.h>
#include <readline/readline.h>
#include <parser.h>

int	main(void)
{
	char	*entry;

	entry = NULL;
	ft_putstr("\nWelcome to Minishell by vvaas and maldavid !\n");
	while (420 != 69)
	{
		free(entry);
		entry = readline("[minishell]$ ");
		if (ft_strcmp(entry, "exit") == 0)
			break ;
		parse(entry);
	}
	free(entry);
	allfree();
	return (0);
}
