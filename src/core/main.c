/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:10:27 by maldavid          #+#    #+#             */
/*   Updated: 2023/07/25 18:22:57 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <utils.h>
#include <stdio.h>
#include <memory.h>
#include <parser.h>
#include <prompt.h>
#include <stdlib.h>
#include <builtin.h>
#include <interactive.h>
#include <readline/history.h>

void	print_parser_info(t_parser_info *info)
{
	int	i;

	if (info == NULL)
		return ;
	ft_printf("command : '%s'\nargs :\n", info->cmd.str);
	i = 0;
	while (info->args[i] != NULL)
	{
		ft_printf("\t'%s'\n", info->args[i]);
		i++;
	}
	if (info->link == NONE)
		ft_putstr("is not linked to next info\n\n");
	else if (info->link == PIPE)
		ft_putstr("is linked to next info by a pipe\n\n");
	else if (info->link == HERE_DOC)
		ft_putstr("is linked to next info by a here doc\n\n");
	else if (info->link == R_IN)
		ft_putstr("is linked to next info by a redirection in\n\n");
	else if (info->link == R_OUT)
		ft_putstr("is linked to next info by a redirection out\n\n");
	else if (info->link == R_OUT_ABSOLUTE)
		ft_putstr("is linked to next info by an absolute redirection out\n\n");
	print_parser_info(info->next);
}

int	main(int ac, char **av, char **env)
{
	t_prompt	prompt;
	char		*entry;

	(void)ac;
	(void)av;
	entry = NULL;
	init_minishell(env);
	while (420 != 69)
	{
		free(entry);
		update_prompt(&prompt);
		entry = display_prompt(&prompt);
	//	ft_printf("-%s-\n", entry);
		if (ft_strlen(entry) != 0 && !prompt.here_doc)
			add_history(entry);
		if (entry == NULL)
		{
			ft_putstr("exit\n");
			break ;
		}
	//	if (ft_strstr("maldavid malo kbz_8", getenv("USER")) != NULL)
	//		print_parser_info(parse(entry));
	//	else
		exec_command(parse(entry));
	}
	free(entry);
	allfree();
	return (0);
}
