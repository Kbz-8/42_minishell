/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_manager2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:57:47 by maldavid          #+#    #+#             */
/*   Updated: 2023/07/26 21:03:34 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdbool.h>

char	*next_here_doc(char *entry, int end_hd)
{
	bool	string;

	string = false;
	while (end_hd > -1 && entry[end_hd])
	{
		if (ft_strchr("\"'", entry[end_hd]))
			string = !string;
		if (entry[end_hd] == '<' && entry[end_hd + 1] == '<' && !string)
			return (entry + end_hd);
		end_hd++;
	}
	return (NULL);
}

int	find_next_here_doc_index(char *entry)
{
	int		i;
	bool	string;

	i = 0;
	string = false;
	while (entry[i])
	{
		if (ft_strchr("\"'", entry[i]))
			string = !string;
		if (entry[i] == '<' && entry[i + 1] == '<' && !string)
			return (i);
		i++;
	}
	return (-2147483640);
}
