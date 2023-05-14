/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:22:55 by maldavid          #+#    #+#             */
/*   Updated: 2023/05/14 11:21:02 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_H
# define MEMORY_H

# include <stddef.h>

typedef struct	s_block
{
	void			*ptr;
	struct s_block	*next;
}	t_block;

void	*alloc(size_t size);
void	dealloc(void *ptr);
void	allfree(void);

#endif
