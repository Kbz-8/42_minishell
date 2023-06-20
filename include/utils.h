/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:27:36 by vvaas             #+#    #+#             */
/*   Updated: 2023/06/20 23:26:00 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdbool.h>
# include <nexus.h>
char	*ft_joinfree(char *dest, char *src);
int		is_exec(char *input);
void	ft_execve(char *path, char **argv, char **env);
bool	is_executable_name(char *name);
bool	is_executable(char *path);
void	ft_exec(char *input);
char	*is_exec_path(char *name);
char	*get_exec_path(char *name);
void	ft_freesplit(char **tab);
char	*create_input(t_parser_info *info);
char	**create_env(void);
bool	is_environment(char *input);
void	add_env(char *input);
#endif
