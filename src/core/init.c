/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:22:37 by maldavid          #+#    #+#             */
/*   Updated: 2023/01/19 15:39:37 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nexus.h>
#include <stdlib.h>

void	init_minishell(void)
{
	add_env_var("PATH", getenv("PATH"));
	add_env_var("USER", getenv("USER"));
	add_env_var("PWD", getenv("PWD"));
}
