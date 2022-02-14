/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:10:30 by agallipo          #+#    #+#             */
/*   Updated: 2022/02/14 11:28:58 by agallipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_pipe(char **argv, char **env, char *command, char **flags)
{
	int	fd1[2];
	int	fd2;
	int	status;
	int pid;

	pipe(fd1);
	pid = fork();
	if (pid == 0)
	{

		close(fd1[0]);
		dup2(fd1[1], open(argv[4], O_WRONLY));
		close(fd1[1]);
		execve(command, flags, env);
		printf("cmd 2= %s\n", command);
		ft_free_matrix(flags);
		//free(command);
		command = 0;
	}
	else
	{
		close(fd1[1]);
		pid = fork();
		if (pid == 0)
		{
			fd2 = open(argv[1], O_WRONLY); //mirar protecciones
			printf("fd2= %d\n", fd2);
			dup2(fd1[0], STDIN_FILENO);
			close(fd1[0]);
			dup2(fd2, open(argv[4], O_WRONLY));
			flags = ft_split(argv[3], ' ');
			command = ft_env_path(env, flags);
			printf("cmd= %s\n", command);
			execve(command, flags, env);
			ft_free_matrix(flags);
		}
		else
			close(fd1[0]);
	}
	wait(&status);
	wait(&status);

	return (0);
}



