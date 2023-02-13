/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:25:46 by vvaas             #+#    #+#             */
/*   Updated: 2023/02/13 09:31:48 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <interactive.h>
#include <stddef.h>
#include <stdio.h>
#include <readline/readline.h>

void	process(int sig)
{
	if (sig == SIGINT)
	{
		rl_on_new_line();
		puts("");
		rl_replace_line("", 0);
		rl_redisplay();
	}
	if (sig == SIGQUIT)
		printf("%c%c  %c%c", 8, 8, 8, 8);
}

void	init_sig(void)
{
	signal(SIGINT, process);
	signal(SIGQUIT, process);
}
