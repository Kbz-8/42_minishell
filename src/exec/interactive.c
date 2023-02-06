/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:25:46 by vvaas             #+#    #+#             */
/*   Updated: 2023/02/06 15:55:54 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <interactive.h>
#include <stddef.h>
#include <stdbool.h>

int	new_prompt(bool	modify)
{
	static bool	value = 0;

	if (modify)
		value = !value;
	return (value);
}
void	process(int sig, siginfo_t *client, void *context)
{
	(void)context;
	(void)client;

	if (sig == SIGINT)
		new_prompt(1);
	else
		return;
}

void	init_sig(struct sigaction *sig)
{
	sig->sa_sigaction = process;
	sigaddset(&sig->sa_mask, SIGINT);
	sigaddset(&sig->sa_mask, SIGQUIT);
	sig->sa_flags = SA_SIGINFO;
	sigaction(SIGINT, sig, NULL);
	sigaction(SIGQUIT, sig, NULL);
}