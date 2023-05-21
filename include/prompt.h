/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:21:30 by maldavid          #+#    #+#             */
/*   Updated: 2023/05/21 16:36:47 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_H
# define PROMPT_H

typedef struct s_prompt
{
	char	*text;
}	t_prompt;

void	init_prompt(t_prompt *prompt);
char	*display_prompt(t_prompt *prompt);

#endif
