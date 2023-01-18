/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:15:00 by vvaas             #+#    #+#             */
/*   Updated: 2023/01/18 12:36:12 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>
#include <libft.h>
#include <unistd.h>
#include <memory.h>
#include <readline/readline.h>
#include <readline/history.h>

#define BUFFER_SIZE 2048

char	*user_input(void)
{
	char *input;

	input = readline(NULL);
	return (input);
}