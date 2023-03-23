/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:20:39 by maldavid          #+#    #+#             */
/*   Updated: 2023/03/23 10:25:19 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define E_UNKOWN			0
# define E_MEMFAIL			1
# define E_PIPES			2
# define E_REDIRECTION		3
# define E_TOO_MANY_ARGS	4
# define NUMBER_REQUIRED	5

enum	e_type
{
	ERROR,
	FATAL_ERROR
};

void	report(enum e_type type, int error);

#endif
