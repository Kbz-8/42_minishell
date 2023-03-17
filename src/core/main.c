/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:10:27 by maldavid          #+#    #+#             */
/*   Updated: 2023/03/17 15:15:28 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtin.h>
#include <libft.h>
#include <memory.h>
#include <stdio.h>
#include <readline/readline.h>
#include <parser.h>
#include <stdlib.h>
#include <interactive.h>
#include <utils.h>
#include <readline/history.h>

void	temp_exec(char *entry)
{
	char *path;
	if (ft_strncmp(entry, "echo", 4) == 0)
		ft_echo(entry);
	else if (ft_strcmp(entry, "pwd") == 0)
		ft_putendl_fd((char *)get_env_var("PWD"), 1);
	else if (ft_strcmp(entry, "env") == 0)
		ft_putendl_fd((char *)get_env_var("ENV"), 1);
	else if (is_exec(entry) == 1)
		ft_exec(entry);
	else if (is_exec(entry) == 2 && ft_strlen(entry) != 0)
	{
		path = get_exec_path(entry);
		ft_exec(path);
		free(path);
	}
	else if (is_exec(entry) == 0 && ft_nstrchr(entry, ' ') == NULL)
		printf("minishell: command not found: %s\n", entry);
}

int	main(void)
{
	char	*entry;
	char	*prompt;
	size_t	username_size;	

	init_minishell();
	entry = NULL;
	ft_putstr("\nWelcome to Minishell by vvaas and maldavid !\n");
	username_size = ft_strlen(getenv("USER"));
	prompt = alloc(username_size + 16);
	prompt[0] = '[';
	ft_strcpy(prompt + 1, getenv("USER"));
	ft_strcpy(prompt + 1 + username_size, "@ minishell]$ ");
	while (420 != 69)
	{
		free(entry);
		entry = readline(prompt);
		if (ft_strlen(entry) != 0)
			add_history(entry);
		if (entry == 0 || ft_strcmp(entry, "exit") == 0)
			break ;
		if (ft_strcmp(getenv("USER"), "maldavid") == 0 || ft_strcmp(getenv("USER"), "kbz_8") == 0)
			(void)parse(entry);
		else
			temp_exec(entry);
	}
	free(entry);
	allfree();
	return (0);
}
