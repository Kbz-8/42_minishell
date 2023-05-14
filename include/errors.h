/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:20:39 by maldavid          #+#    #+#             */
/*   Updated: 2023/05/14 12:49:02 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define E_UNKOWN			0
# define E_MEMFAIL			1
# define E_SANITIZE_NEAR	2
# define E_TOO_MANY_ARGS	3
# define NUMBER_REQUIRED	4

enum	e_type
{
	ERROR,
	FATAL_ERROR
};

void	report(enum e_type type, int error);

#endif
