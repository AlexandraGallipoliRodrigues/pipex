/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <agallipo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:31:14 by agallipo          #+#    #+#             */
/*   Updated: 2022/02/09 13:10:11 by agallipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_find_command(char **env)
{
	char	**path;
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp("PATH=", env[i], 5) == 0)
		{
			path = ft_split(env[i], ':');
			break;
		}
		i++;
	}
	return (path);
}

char	*ft_command_env(char **env)
{
	char	**path;
	char	*command;
	int		i;

	i = 0;
	path = ft_find_command(env);
	while (path[i])
	{
		command = ft_strjoin(command, path[i]);
		i++;
	}
	ft_free_matrix(path);
//	if (access(command, R_OK) == -1 || access(command, X_OK == -1))
//			exit (1);
	return (command);
}
