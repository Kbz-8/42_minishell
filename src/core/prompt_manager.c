/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:21:17 by maldavid          #+#    #+#             */
/*   Updated: 2023/07/25 18:22:16 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>
#include <nexus.h>
#include <stdint.h>
#include <prompt.h>
#include <stddef.h>
#include <memory.h>
#include <stdbool.h>
#include <readline/readline.h>

void	update_prompt(t_prompt *prompt)
{
	size_t	username_size;
	size_t	pwd_size;

	if (prompt->text != NULL)
		dealloc(prompt->text);
	username_size = ft_strlen(get_env_var("USER"));
	pwd_size = ft_strlen(get_env_var("PWD"));
	prompt->text = alloc(username_size + pwd_size + 20);
	ft_memset(prompt->text, 0, username_size + pwd_size + 20);
	ft_strcpy(prompt->text, "[minishell @");
	ft_strcpy(prompt->text + 12, get_env_var("USER"));
	ft_strcpy(prompt->text + 12 + username_size, " | ");
	ft_strcpy(prompt->text + 12 + username_size + 3, get_env_var("PWD"));
	ft_strcpy(prompt->text + 12 + username_size + 3 + pwd_size, "]$ ");
}

static void	here_doc(char **entry, char *eof, bool double_quoted)
{
	char	*new_line;
	char	*new_entry;
	size_t	i;
	size_t	j;
	bool	continue_doc;

	i = 0;
	new_line = readline("heredoc> ");
	j = ft_strlen(*entry);
	new_entry = malloc(j + ft_strlen(new_line) + 2);
	ft_memset(new_entry, 0, j + ft_strlen(new_line) + 2);
	ft_strcpy(new_entry, *entry);
	free(*entry);
	continue_doc = (ft_strcmp(new_line, eof) != 0);
	while (continue_doc && new_line[i] != 0)
		new_entry[j++] = new_line[i++];
	free(new_line);
	*entry = new_entry;
	new_entry[j] = '\n';
	if (continue_doc)
		here_doc(entry, eof, double_quoted);
	else
		new_entry[j] = '"' + (!double_quoted * 5);
}

static void	skip(char **ptr, bool only_spaces)
{
	while (*(*ptr))
	{
		if (only_spaces && !ft_isspace(*(*ptr)))
			return ;
		(*ptr)++;
	}
}

static void	prepare_here_doc(char **entry, char *ptr)
{
	char	*eof;
	char	*command;
	size_t	i;
	bool	double_quoted;

	i = 0;
	double_quoted = false;
	while (ptr[i] && (!ft_isspace(ptr[i]) || double_quoted))
	{
		if (ptr[i] == '"' && double_quoted)
			break ;
		if (ptr[i] == '"')
			double_quoted = true;
		i++;
	}
	eof = ft_strndup(ptr + double_quoted, i - (double_quoted));
	command = ft_strdup(ptr + i);
	ft_memset(ptr, ' ', ft_strlen(ptr));
	skip(&ptr, false);
	ptr[0 - !double_quoted] = '"' + (!double_quoted * 5);
	here_doc(entry, eof, double_quoted);
	dealloc(eof);
	ptr = malloc(ft_strlen(command) + ft_strlen(*entry) + 1);
	ft_memset(ptr, 0, ft_strlen(command) + ft_strlen(*entry) + 1);
	ft_strcpy(ptr, *entry);
	free(*entry);
	ft_strcpy(ptr + ft_strlen(ptr), command);
	*entry = ptr;
}

char	*display_prompt(t_prompt *prompt)
{
	char	*ptr;
	char	*entry;

	entry = readline(prompt->text);
	get_env_data()->here_doc = false;
	if (!entry)
		return (NULL);
	ptr = ft_strstr(entry, "<<");
	prompt->here_doc = false;
	if (ptr != NULL)
	{
		get_env_data()->here_doc = true;
		prompt->here_doc = true;
		ptr += 2;
		skip(&ptr, true);
		prepare_here_doc(&entry, ptr);
	}
	return (entry);
}
