/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:20:39 by maldavid          #+#    #+#             */
/*   Updated: 2023/01/19 09:48:47 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define E_UNKOWN		0
# define E_MEMFAIL		1
# define E_PIPES		2

enum	e_type
{
	ERROR,
	FATAL_ERROR
};

void	report(enum e_type type, int error);

#endif
