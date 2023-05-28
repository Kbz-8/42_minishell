/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:21:17 by maldavid          #+#    #+#             */
/*   Updated: 2023/05/28 16:53:32 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prompt.h>
#include <stddef.h>
#include <libft.h>
#include <memory.h>
#include <stdio.h>
#include <readline/readline.h>
#include <stdbool.h>

void	init_prompt(t_prompt *prompt)
{
	size_t	username_size;	

	ft_putstr("\nWelcome to Minishell by vvaas and maldavid !\n");
	username_size = ft_strlen(getenv("USER"));
	prompt->text = alloc(username_size + 16);
	ft_memset(prompt->text, 0, username_size + 16);
	prompt->text[0] = '[';
	ft_strcpy(prompt->text + 1, getenv("USER"));
	ft_strcpy(prompt->text + 1 + username_size, "@ minishell]$ ");
}

static void	incomplete_string(char *entry)
{
	(void)entry;
}

char	*display_prompt(t_prompt *prompt)
{
	char	*entry;
	size_t	i;
	bool	in_string;

	i = 0;
	in_string = false;
	entry = readline(prompt->text);
	while (entry[i] != 0)
	{
		if (entry[i] == '"' || entry[i] == '\'')
			in_string = !in_string;
		i++;
	}
	if (in_string)
		incomplete_string(entry);
	return (entry);
}