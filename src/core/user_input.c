/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:15:00 by vvaas             #+#    #+#             */
/*   Updated: 2023/01/18 11:51:02 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>
#include <libft.h>
#include <unistd.h>
#include <memory.h>

#define BUFFER_SIZE 2048

char	*user_input()
{
	char *input;
	int len_input;
	char *tmp;

	input = NULL;
	tmp = kalloc(BUFFER_SIZE, 1);
	len_input = read(0, tmp, BUFFER_SIZE);
	if (len_input <= 0)
	{
		dealloc(tmp);
		return (NULL);
	}
	while (len_input == 2048)
	{
		input = ft_joinfree(input, tmp);
		len_input = read(0, tmp, BUFFER_SIZE);
		tmp[len_input] = 0;
	}
	input = ft_joinfree(input, tmp);
	input[ft_strlen(input) - 1] = 0;
	return (input);
}