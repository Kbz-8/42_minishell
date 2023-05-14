/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:22:37 by maldavid          #+#    #+#             */
/*   Updated: 2023/05/14 11:08:23 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nexus.h>
#include <stdlib.h>
#include <interactive.h>
#include <memory.h>
#include <libft.h>

void	init_minishell(void)
{
	add_env_var("PATH", getenv("PATH"));
	add_env_var("USER", getenv("USER"));
	add_env_var("PWD", getenv("PWD"));
	init_sig();
	ft_set_internal_malloc(alloc);
	ft_set_internal_free(dealloc);
}
