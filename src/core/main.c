/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:10:27 by maldavid          #+#    #+#             */
/*   Updated: 2023/01/18 12:05:41 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <user_input.h>
#include <libft.h>
#include <memory.h>

int	main(void)
{
	char *pouic = user_input();
	allfree();
	return (0);
}
