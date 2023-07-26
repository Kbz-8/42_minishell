/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:21:30 by maldavid          #+#    #+#             */
/*   Updated: 2023/07/26 20:04:57 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_H
# define PROMPT_H

# include <stdbool.h>

typedef struct s_prompt
{
	char	*text;
	bool	here_doc;
}	t_prompt;

void	update_prompt(t_prompt *prompt);
char	*display_prompt(t_prompt *prompt);

#endif
