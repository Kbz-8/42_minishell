/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:27:36 by vvaas             #+#    #+#             */
/*   Updated: 2023/07/25 22:09:28 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdbool.h>
# include <nexus.h>
# include <stddef.h>

char			*ft_joinfree(char *dest, char *src);
int				is_exec(char *input);
void			ft_execve(char *path, char **argv, char **env);
bool			is_executable_name(char *name);
bool			is_executable(char *path);
void			ft_exec(char *input);
char			*is_exec_path(char *name);
char			*get_exec_path(char *name);
void			ft_freesplit(char **tab);
char			*create_input(t_parser_info *info);
char			**create_env(void);
bool			is_environment(char *input);
void			add_env(char *input);
void			ft_export(t_parser_info *info);
char			**create_env(void);
int				ft_setcwd(t_parser_info *info);
t_parser_info	*r_in(t_parser_info *info);
t_parser_info	*r_doc(t_parser_info *info);
t_parser_info	*r_out(t_parser_info *info);
void			append_value(int *tab, int val);
char			**create_tab(char **env_tab, t_env_var *args);
bool			check_validity(char *info);
void			append_value(int *tab, int val);
bool			r_in_error(t_parser_info *info);
t_parser_info	*jump_next_pipe(t_parser_info *info);
t_parser_info	*jump_next(t_parser_info *info);
void			exec_command(t_parser_info *info);
void			command(t_parser_info *info);
void			c_pipe(t_parser_info *info);
char			*ft_strndup_malloc(const char *s, size_t n);

#endif
