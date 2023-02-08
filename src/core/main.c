/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:10:27 by maldavid          #+#    #+#             */
/*   Updated: 2023/02/08 18:20:17 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <user_input.h>
#include <libft.h>
#include <memory.h>
#include <stdio.h>
#include <readline/readline.h>
#include <parser.h>
#include <stdlib.h>
#include <interactive.h>

int	main(void)
{
	char	*entry;
	char	*prompt;
	size_t	username_size;	

	init_minishell();
	init_sig();
	entry = NULL;
	ft_putstr("\nWelcome to Minishell by vvaas and maldavid !\n");
	username_size = ft_strlen(getenv("USER"));
	prompt = alloc(username_size + 16);
	prompt[0] = '[';
	ft_strcpy(prompt + 1, getenv("USER"));
	ft_strcpy(prompt + 1 + username_size, "@ minishell]$ ");
	while (420 != 69)
	{
		free(entry);
		entry = readline(prompt);
		if (entry == 0 || ft_strcmp(entry, "exit") == 0	)
			break ;
		if (ft_strlen(entry) != 0)
			printf("%s\n", entry);
	}
	free(entry);
	allfree();
	return (0);
}
