/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 21:09:09 by vvaas             #+#    #+#             */
/*   Updated: 2023/08/03 21:38:21 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nexus.h>
#include <libft.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>

t_parser_info	*jump_next_pipe(t_parser_info *info)
{
	t_parser_info	*tmp;

	tmp = info;
	while (tmp->next && tmp->link != PIPE)
		tmp = tmp->next;
	if (tmp->next == NULL)
		return (NULL);
	return (tmp);
}

bool	is_a_dir(char *path)
{
	struct stat	file;

	stat(path, &file);
	if (S_ISDIR(file.st_mode))
	{
		printf("minishell: %s: Is a directory\n", path);
		get_env_data()->last_return = 127;
		return (1);
	}
	return (0);
}

t_parser_info	*jump_next(t_parser_info *info)
{
	t_parser_info	*tmp;

	if (info == NULL)
		return (NULL);
	if (info->next == NULL)
		return (NULL);
	tmp = info;
	tmp->link = info->next->link;
	tmp->next = info->next->next;
	return (tmp);
}

bool	r_in_error(t_parser_info *info)
{
	struct stat	file;

	if (stat(info->next->args[0], &file) == -1)
	{
		printf("minishell: %s: No such file or directory\n", \
		info->next->args[0]);
		get_env_data()->last_return = 127;
		return (1);
	}
	if (is_a_dir((char *)info->next->args[0]))
		return (1);
	if (access(info->next->args[0], R_OK) != 0)
	{
		printf("minishell: %s: Permission denied\n", info->next->args[0]);
		get_env_data()->last_return = 1;
		return (1);
	}
	return (0);
}

void	append_value(int *tab, int val)
{
	int	i;

	i = 0;
	while (tab[i] != 0)
		i++;
	tab[i] = val;
}
