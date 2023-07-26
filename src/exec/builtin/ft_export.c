/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 02:29:32 by vvaas             #+#    #+#             */
/*   Updated: 2023/07/26 15:34:32 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nexus.h>
#include <utils.h>
#include <libft.h>

void	print_args(char **args)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (args[i])
	{
		ft_printf("declare -x ");
		while (args[i][j] != '=' && args[i][j])
			ft_printf("%c", args[i][j++]);
		if (!args[i][j + 1])
		{
			ft_printf("\n");
			i++;
			j = 0;
			continue ;
		}
		ft_printf("%c", args[i][j++]);
		ft_printf("\"");
		while (args[i][j])
			ft_printf("%c", args[i][j++]);
		ft_printf("\"\n");
		i++;
		j = 0;
	}
}

void	print_sorted_env(void)
{
	char	**buffer;
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 1;
	buffer = create_env();
	while (buffer[i])
	{
		while (buffer[j])
		{
			if (ft_strcmp(buffer[i], buffer[j]) > 0)
			{
				tmp = buffer[i];
				buffer[i] = buffer[j];
				buffer[j] = tmp;
			}
			j++;
		}
		i++;
		j = i + 1;
	}
	print_args(buffer);
}

bool	is_valid(const char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '=')
		return (false);
	while (arg[i] && arg[i] != '=')
	{
		if (!ft_isalnum(arg[i]))
			return (false);
		i++;
	}
	return (true);
}

void	ft_export(t_parser_info *info)
{
	int	i;

	i = 1;
	if (info->args[1] == NULL)
		print_sorted_env();
	while (info->args[i])
	{
		if (!is_valid(info->args[i]))
		{
			ft_printf("minishell: export: `%s': not a valid identifier\n", \
			info->args[i]);
			i++;
			continue ;
		}
		add_env((char *)info->args[i]);
		i++;
	}
	get_env_data()->last_return = 0;
}
