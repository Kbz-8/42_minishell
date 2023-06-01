/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:21:17 by maldavid          #+#    #+#             */
/*   Updated: 2023/06/01 17:29:27 by maldavid         ###   ########.fr       */
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

char	*display_prompt(t_prompt *prompt)
{
	return (readline(prompt->text));
}
