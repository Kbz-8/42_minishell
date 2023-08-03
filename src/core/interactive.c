/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:25:46 by vvaas             #+#    #+#             */
/*   Updated: 2023/08/03 17:56:57 by vvaas            ###   ########.fr       */
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
#include <memory.h>
#include <utils.h>

void	process_sigpipe(int sig)
{
	if (sig == SIGPIPE)
	{
		hard_close(false);
		allfree();
		exit(128 + SIGPIPE);
	}
}

void	process(int sig)
{
	if (sig == SIGINT && get_env_data()->listen == 2)
	{
		get_env_data()->fd_input_save = dup(0);
		close(0);
		ft_putchar('\n');
		get_env_data()->last_return = 130;
	}
	else if (sig == SIGINT && get_env_data()->listen == 1)
	{
		rl_on_new_line();
		ft_putchar('\n');
		rl_replace_line("", 0);
		rl_redisplay();
		get_env_data()->last_return = 130;
	}
	else if (sig == SIGINT && get_env_data()->listen == 0)
		ft_putchar('\n');
	if (sig == SIGQUIT)
		printf("%c%c  %c%c", 8, 8, 8, 8);
}

void	init_sig(void)
{
	signal(SIGINT, process);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGPIPE, process_sigpipe);
	get_env_data()->last_return = 0;
	get_env_data()->listen = 1;
	get_env_data()->fd = -1;
	get_env_data()->fd_input_save = -1;
}
