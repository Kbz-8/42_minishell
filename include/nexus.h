/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nexus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:59:38 by maldavid          #+#    #+#             */
/*   Updated: 2023/01/19 07:55:22 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NEXUS_H
# define NEXUS_H

enum	e_builtin
{
	ECHO = 1,
	CD = 2,
	PWD = 3,
	EXPORT = 4,
	UNSET = 5,
	ENV = 6,
	EXIT = 7
};

typedef union u_cmd
{
	enum e_builtin	builtin;
	const char		*str;
}	t_cmd;

typedef struct s_parser_info
{
	t_cmd					cmd;
	const char				*args;
	struct s_parser_info	*next;
}	t_parser_info;

typedef struct s_env_var
{
	const char			*key;
	const char			*value;
	struct s_env_var	*next;
}	t_env_var;

typedef struct s_env
{
	t_env_var	*vars;
	int			last_return;
}	t_env;

t_env	*get_env_data(void);

#endif
