/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <agallipo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:16:08 by agallipo          #+#    #+#             */
/*   Updated: 2022/02/17 13:31:54 by agallipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*ft_env_path(char **env, char *argv, char **flags)
{
	char	**path;
	char	*cmd;
	int		i;

	if (argv[0] == '/' && access(argv, X_OK | R_OK) == 0)
		return (argv);
	path = ft_path_split(env);
	i = 0;
	while (path[i])
	{
		cmd = strdup(path[i]);
		ft_strlcat(cmd, "/", ft_strlen(cmd) + 2);
		ft_strlcat(cmd, flags[0], ft_strlen(cmd) + ft_strlen(flags[0]) + 1);
		if (access(cmd, X_OK | R_OK) == 0)
			return (cmd);
		i++;
	}
	free(cmd);
	ft_free_matrix(path);
	printf("pipex: command not found: %s\n", argv);
	return (0);
}

char	**ft_path_split(char **env)
{
	char	**path;
	int		i;

	i = 0;
	path = NULL;
	while (env[i] != NULL)
	{
		if (ft_strncmp("PATH=", env[i], 5) == 0)
		{
			path = ft_split(env[i], ':');
			break ;
		}
		i++;
	}
	return (path);
}
