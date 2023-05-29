/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:21:17 by maldavid          #+#    #+#             */
/*   Updated: 2023/05/29 17:11:25 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>
#include <prompt.h>
#include <stddef.h>
#include <memory.h>
#include <stdbool.h>
#include <readline/readline.h>

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

static void	incomplete_string(char **entry)
{
	char	*new_line;
	char	*new_entry;
	size_t	i;
	size_t	j;
	bool	in_string;

	i = 0;
	in_string = true;
	new_line = readline("> ");
	j = ft_strlen(*entry);
	new_entry = malloc(j + ft_strlen(new_line) + 2);
	ft_memset(new_entry, 0, j + ft_strlen(new_line) + 2);
	ft_strcpy(new_entry, *entry);
	new_entry[j] = '\n';
	j++;
	while (new_line[i] != 0)
	{
		if (new_line[i] == '"' || new_line[i] == '\'')
			in_string = !in_string;
		new_entry[j++] = new_line[i++];
	}
	if (in_string)
		incomplete_string(&new_entry);
	free(*entry);
	*entry = new_entry;
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
		incomplete_string(&entry);
	return (entry);
}
