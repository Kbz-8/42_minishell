/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:18:11 by maldavid          #+#    #+#             */
/*   Updated: 2023/05/14 12:48:52 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errors.h>
#include <stdlib.h>
#include <libft.h>
#include <memory.h>

#define ERRORS_NUMBER 5

static const char	*get_str_error(int error)
{
	static const char	*errors[ERRORS_NUMBER] = {
		"unknown error",
		"memory allocation failed",
		"parse error near an operator",
		"too many arguments",
		"numerical argument required"
	};

	return (errors[error]);
}

void	report(enum e_type type, int error)
{
	if (type == FATAL_ERROR)
		ft_putstr_fd("Fatal Error : ", 2);
	else
		ft_putstr_fd("Error : ", 2);
	if (error < 0 || error >= ERRORS_NUMBER)
		error = 0;
	ft_putstr_fd((char *)get_str_error(error), 2);
	ft_putchar_fd('\n', 2);
	if (type == FATAL_ERROR)
	{
		allfree();
		exit(EXIT_SUCCESS);
	}
}
