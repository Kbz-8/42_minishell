/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nexus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:59:38 by maldavid          #+#    #+#             */
/*   Updated: 2023/07/26 18:06:15 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NEXUS_H
# define NEXUS_H

# include <stdbool.h>
# include <stdint.h>

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
	R_OUT = 2,
	R_OUT_ABSOLUTE = 3,
	R_IN = 4,
	HERE_DOC = 5
};

typedef struct u_cmd
{
	enum e_builtin	builtin;
	char			*str;
}	t_cmd;

typedef struct s_env_var
{
	char				*key;
	char				*value;
	struct s_env_var	*next;
}	t_env_var;

typedef struct s_parser_info
{
	t_cmd					cmd;
	const char				**args;
	enum e_command_link		link;
	struct s_parser_info	*next;
}	t_parser_info;

typedef struct s_env
{
	t_env_var	*vars;
	int			last_return;
	int			fd;
	int			fd_input_save;
	uint8_t		listen;
	bool		loop;
}	t_env;

t_env		*get_env_data(void);
void		init_minishell(char **env);
void		add_env_var(char *key, char *value);
const char	*get_env_var(char *key);
void		remove_env_var(char *key);
void		modify_env_var(char *key, char *new_key, char *new_value);
#endif
