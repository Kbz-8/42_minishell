/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:13:35 by vvaas             #+#    #+#             */
/*   Updated: 2023/07/24 18:06:21 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include <nexus.h>

void	exec_command(t_parser_info *info);
void	ft_exit(t_parser_info *info);
int		ft_cd(t_parser_info *info);
int		ft_pwd(void);
void	ft_export(t_parser_info *info);
void	ft_echo(t_parser_info *info);
int		ft_env(t_parser_info *info);
void	ft_unset(t_parser_info *info);
#endif
