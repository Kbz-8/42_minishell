/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:21:17 by maldavid          #+#    #+#             */
/*   Updated: 2023/07/26 21:13:28 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>
#include <nexus.h>
#include <utils.h>
#include <stdint.h>
#include <prompt.h>
#include <stddef.h>
#include <unistd.h>
#include <errors.h>
#include <memory.h>
#include <stdbool.h>
#include <readline/readline.h>

char	*next_here_doc(char *entry, int end_hd);
int		find_next_here_doc_index(char *entry);

void	update_prompt(t_prompt *prompt)
{
	size_t	username_size;
	size_t	pwd_size;
	char	*pwd;

	if (prompt != NULL && prompt->text != NULL)
		dealloc(prompt->text);
	pwd = (char *)getcwd(NULL, 0);
	username_size = ft_strlen(get_env_var("USER"));
	pwd_size = ft_strlen(pwd);
	prompt->text = alloc(username_size + pwd_size + 20);
	ft_strcpy(prompt->text, "[minishell @");
	if (username_size != 0)
		ft_strcpy(prompt->text + 12, get_env_var("USER"));
	ft_strcpy(prompt->text + 12 + username_size, " | ");
	ft_strcpy(prompt->text + 12 + username_size + 3, pwd);
	ft_strcpy(prompt->text + 12 + username_size + 3 + pwd_size, "]$ ");
	free(pwd);
	if (get_env_data()->fd_input_save != -1)
	{
		dup2(get_env_data()->fd_input_save, 0);
		close(get_env_data()->fd_input_save);
		get_env_data()->fd_input_save = -1;
	}
}

static void	here_doc(char **entry, char *eof, bool double_quoted)
{
	char	*new[2];
	size_t	i[2];
	bool	continue_doc;

	i[0] = 0;
	new[0] = readline("heredoc> ");
	if (new[0] == NULL)
	{
		free(*entry);
		*entry = ft_strndup_malloc("", 0);
		return ;
	}
	i[1] = ft_strlen(*entry);
	new[1] = ft_strndup_malloc(*entry, i[1] + ft_strlen(new[0]) + 2);
	free(*entry);
	continue_doc = (ft_strcmp(new[0], eof) != 0);
	while (continue_doc && new[0][i[0]] != 0)
		new[1][i[1]++] = new[0][i[0]++];
	free(new[0]);
	*entry = new[1];
	new[1][i[1]] = '\n';
	if (continue_doc)
		here_doc(entry, eof, double_quoted);
	else
		new[1][i[1]] = '"' + (!double_quoted * 5);
}

static void	skip(char **ptr, bool only_spaces)
{
	get_env_data()->listen = 2;
	while (*(*ptr))
	{
		if (only_spaces && !ft_isspace(*(*ptr)))
			return ;
		(*ptr)++;
	}
}

static char	*prepare_here_doc(char **entry, char *p, int *end_hd, int *i)
{
	char	*buf[2];
	bool	dq;

	*i = 0;
	dq = false;
	while (p[*i] && ((!ft_isspace(p[*i]) && !ft_strchr("<>|", p[*i])) || dq))
	{
		if (p[*i] == '"' && dq)
			break ;
		dq = ((p[(*i)++] == '"') + dq);
	}
	buf[0] = ft_strndup(p + dq, *i - (dq));
	if (ft_strlen(buf[0]) == 0 || ft_strchr("<>|", buf[0][0]) != NULL)
		report(ERROR, E_SANITIZE_NEAR);
	if (ft_strlen(buf[0]) == 0 || ft_strchr("<>|", buf[0][0]) != NULL)
		return (ft_strndup_malloc("", 1));
	buf[1] = ft_strdup(p + *i);
	ft_memset(p, ' ', ft_strlen(p));
	skip(&p, false);
	p[0 - !dq] = '"' + (!dq * 5);
	here_doc(entry, buf[0], dq);
	p = ft_strndup_malloc(*entry, ft_strlen(buf[1]) + ft_strlen(*entry) + 1);
	*end_hd = find_next_here_doc_index(buf[1]) + ft_strlen(p);
	ft_strcpy(p + ft_strlen(p), buf[1]);
	return (p);
}

char	*display_prompt(t_prompt *prompt)
{
	char	*p;
	char	*entry;
	char	*tmp;
	int		end_hd;
	int		i;

	entry = readline(prompt->text);
	if (!entry)
		return (NULL);
	end_hd = find_next_here_doc_index(entry);
	p = entry + end_hd;
	prompt->here_doc = false;
	while (p != NULL && end_hd > -1 && ft_strlen(entry))
	{
		prompt->here_doc = true;
		p += 2;
		skip(&p, true);
		tmp = prepare_here_doc(&entry, p, &end_hd, &i);
		free(entry);
		entry = tmp;
		p = next_here_doc(entry, end_hd);
	}
	return (entry);
}
