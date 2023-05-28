/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nexus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:59:38 by maldavid          #+#    #+#             */
/*   Updated: 2023/05/28 16:53:55 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NEXUS_H
# define NEXUS_H

# include <stdbool.h>

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

enum	e_command_link
{
	NONE = 0,
	PIPE = 1,
	R_IN = 2,
	R_OUT = 3,
	R_OUT_ABSOLUTE = 4
};

typedef union u_cmd
{
	enum e_builtin	builtin;
	char			*str;
	bool			has_command;
}	t_cmd;

typedef struct s_parser_info
{
	t_cmd					cmd;
	const char				**args;
	enum e_command_link		link;
	struct s_parser_info	*next;
}	t_parser_info;

typedef struct s_env_var
{
	char				*key;
	char				*value;
	struct s_env_var	*next;
}	t_env_var;

typedef struct s_env
{
	t_env_var	*vars;
	int			last_return;
}	t_env;

t_env		*get_env_data(void);
void		init_minishell(void);
void		add_env_var(char *key, char *value);
const char	*get_env_var(char *key);

#endif
