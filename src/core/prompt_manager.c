/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:21:17 by maldavid          #+#    #+#             */
/*   Updated: 2023/05/31 20:51:16 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>
#include <nexus.h>
#include <stdint.h>
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

static void	incomplete_string(char **entry, uint8_t in_string)
{
	char	*new_line;
	char	*new_entry;
	size_t	i;
	size_t	j;

	i = 0;
	new_line = readline("> ");
	j = ft_strlen(*entry);
	new_entry = malloc(j + ft_strlen(new_line) + 2);
	ft_memset(new_entry, 0, j + ft_strlen(new_line) + 2);
	ft_strcpy(new_entry, *entry);
	new_entry[j++] = '\n';
	while (new_line[i] != 0)
	{
		if ((in_string & BITS_DOUBLE_QUOTES) == 1 && new_line[i] == '"')
			in_string = 0;
		else if ((in_string & BITS_SINGLE_QUOTES) == 1 && new_line[i] == '\'')
			in_string = 0;
		new_entry[j++] = new_line[i++];
	}
	free(*entry);
	if (get_env_data()->stop_prompt)
	{
		dealloc(new_entry);
		*entry = NULL;
		return ;
	}
	*entry = new_entry;
	if (in_string)
		incomplete_string(&new_entry, in_string);
}

char	*display_prompt(t_prompt *prompt)
{
	char	*entry;
	size_t	i;
	uint8_t	in_string;

	i = 0;
	in_string = 0;
	entry = readline(prompt->text);
	while (entry[i] != 0)
	{
		if (entry[i] == '"' && (in_string & BITS_SINGLE_QUOTES) == 0)
			in_string = BITS_DOUBLE_QUOTES;
		else if (entry[i] == '\'' && (in_string & BITS_DOUBLE_QUOTES) == 0)
			in_string = BITS_SINGLE_QUOTES;
		i++;
	}
	if (in_string)
		incomplete_string(&entry, in_string);
	return (entry);
}
