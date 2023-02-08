/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactive.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:26:51 by vvaas             #+#    #+#             */
/*   Updated: 2023/02/06 16:51:01 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERACTIVE_H
# define INTERACTIVE_H

#include <signal.h>
#include <stdbool.h>

void	init_sig(struct sigaction *sig);
void	process(int sig, siginfo_t *client, void *context);

#endif