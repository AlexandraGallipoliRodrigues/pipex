/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:01:50 by agallipo          #+#    #+#             */
/*   Updated: 2022/02/11 11:42:51 by agallipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int main(int argc, char **argv, char **env)
{
	char	*command;
	char	**flags;

	argc = 0;
	flags = ft_split(argv[1], ' ');
	command = ft_env_path(env, flags);
	ft_pipe(argv, env, command, flags);
	//system("leaks -q pipex");
	return (0);
}
