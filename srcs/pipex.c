/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <agallipo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 10:35:00 by agallipo          #+#    #+#             */
/*   Updated: 2022/02/09 13:09:45 by agallipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **env)
{
	char	*c;
	c = ft_command_env(env);
	printf("%s\n", c);
	c = ft_strjoin(c, argv[1]);
	printf("%s\n", c);
	execve(c, argv, env);
	system("leaks pipex");
	return (0);
}
