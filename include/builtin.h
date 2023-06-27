/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:13:35 by vvaas             #+#    #+#             */
/*   Updated: 2023/06/26 17:15:30 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include <nexus.h>

void	command(t_parser_info *info);
void	ft_exit(t_parser_info *info);
int		ft_cd(t_parser_info *info);
int		ft_pwd(t_parser_info *info);
void	ft_export(t_parser_info *info);
void	ft_echo(t_parser_info *info);
int		ft_env(t_parser_info *info);

#endif
