/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:25:46 by vvaas             #+#    #+#             */
/*   Updated: 2023/06/24 20:08:11 by vvaas            ###   ########.fr       */
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
	if (sig == SIGINT)
	{
		rl_on_new_line();
		ft_putchar('\n');
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
