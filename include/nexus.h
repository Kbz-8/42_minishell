/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nexus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:59:38 by maldavid          #+#    #+#             */
/*   Updated: 2023/01/18 12:34:48 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NEXUS_H
# define NEXUS_H

typedef enum	e_command
{
	ECHO,
	CD,
	PWD,
	EXPORT,
	UNSET,
	ENV,
	EXIT
}	t_command;

typedef struct	s_parser_info
{
	t_command	command;
	const char	*args;
}	t_parser_info;

typedef struct	s_env
{
	int	last_return;
}	t_env;

#endif
