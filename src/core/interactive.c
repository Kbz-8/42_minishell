/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:25:46 by vvaas             #+#    #+#             */
/*   Updated: 2023/05/31 20:43:48 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <interactive.h>
#include <stddef.h>
#include <stdio.h>
#include <readline/readline.h>
#include <signal.h>
#include <unistd.h>
#include <nexus.h>
#include <libft.h>

void	process(int sig)
{
	static bool	listen = 1;

	if (sig == SIGUSR1)
		listen = !listen;
	if (!listen)
		return;
	if (sig == SIGINT)
	{
		rl_on_new_line();
		ft_putchar('\n');
		rl_replace_line("", 0);
		rl_redisplay();
		get_env_data()->stop_prompt = true;
	}
	if (sig == SIGQUIT)
		printf("%c%c  %c%c", 8, 8, 8, 8);
}

void	init_sig(void)
{
	signal(SIGUSR1, process);
	signal(SIGINT, process);
	signal(SIGQUIT, process);
}
