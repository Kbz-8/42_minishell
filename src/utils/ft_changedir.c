/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_changedir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 20:44:18 by vvaas             #+#    #+#             */
/*   Updated: 2023/07/28 21:07:31 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nexus.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_changedir(void)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	modify_env_var("OLDPWD", "OLDPWD", cwd);
	free(cwd);
	if (!get_env_var("PWD"))
		remove_env_var("OLDPWD");
	chdir(get_env_var("HOME"));
	modify_env_var("PWD", "PWD", (char *)get_env_var("HOME"));
	get_env_data()->last_return = 0;
}
