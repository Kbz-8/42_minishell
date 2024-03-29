/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:10:27 by maldavid          #+#    #+#             */
/*   Updated: 2023/07/30 20:14:12 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <utils.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#include <parser.h>
#include <prompt.h>
#include <stdlib.h>
#include <builtin.h>
#include <interactive.h>
#include <readline/history.h>

int	main(int ac, char **av, char **env)
{
	t_prompt	*prompt;
	char		*entry;

	(void)ac;
	(void)av;
	entry = NULL;
	init_minishell(env);
	prompt = alloc(sizeof(t_prompt));
	while (420 != 69)
	{
		free(entry);
		update_prompt(prompt);
		get_env_data()->listen = 1;
		entry = display_prompt(prompt);
		if (ft_strlen(entry) != 0 && !prompt->here_doc)
			add_history(entry);
		if (entry == NULL)
			ft_exit(NULL);
		exec_command(parse(entry), 0);
	}
	return (0);
}
