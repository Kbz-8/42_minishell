/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:27:36 by vvaas             #+#    #+#             */
/*   Updated: 2023/03/09 16:28:40 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

char	*ft_joinfree(char *dest, char *src);
int	is_exec(char *input);
void	ft_exec(char *input);
bool	is_exec_path(char *name);
char *get_exec_path(char *name);
void	ft_freesplit(char **tab);
#endif