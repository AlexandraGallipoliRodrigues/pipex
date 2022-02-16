/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <agallipo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:10:30 by agallipo          #+#    #+#             */
/*   Updated: 2022/02/16 17:39:15 by agallipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_frst_child(int *fd, char **argv, char **env, int fd2)
{
	char	**flags;
	char	*command;

	flags = ft_split(argv[2], ' ');
	command = ft_env_path(env, argv[2], flags);
	dup2(fd2, STDIN_FILENO);
	close(fd[READ_END]);
	dup2(fd[WRITE_END], STDOUT_FILENO);
	close(fd[WRITE_END]);
	execve(command, flags, env);
	ft_free_matrix(flags);
}

void	ft_bastards(int *fd, char **argv, char **env, int fd2)
{
	char	**flags;
	char	*command;

	dup2(fd[READ_END], STDIN_FILENO);
	close(fd[READ_END]);
	dup2(fd2, STDOUT_FILENO);
	flags = ft_split(argv[3], ' ');
	command = ft_env_path(env, argv[3], flags);
	execve(command, flags, env);
	ft_free_matrix(flags);
}

int	ft_pipe(char **argv, char **env, int fd, int fd2)
{
	int	fd1[2];
	int	status;
	int	pid;

	pipe(fd1);
	pid = fork();
	if (pid == 0)
		ft_frst_child(fd1, argv, env, fd);
	else
	{
		close(fd1[WRITE_END]);
		pid = fork();
		if (pid == 0)
			ft_bastards(fd1, argv, env, fd2);
		else
			close(fd1[READ_END]);
	}
	wait(&status);
	wait(&status);
	return (0);
}
