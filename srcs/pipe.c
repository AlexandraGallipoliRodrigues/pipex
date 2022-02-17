/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <agallipo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:10:30 by agallipo          #+#    #+#             */
/*   Updated: 2022/02/16 23:47:25 by agallipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_frst_child(int *fd, char **argv, char **env)
{
	char	**flags;
	char	*command;
	int		fd2;

	if (!*argv[2])
		return ;
	close(fd[READ_END]);
	fd2 = open(argv[1], O_RDONLY);
	if (fd2 < 0)
	{
		printf("pipex: error file: %s", argv[1]);
		exit (0);
	}
	dup2(fd2, STDIN_FILENO);
	close(fd2);
	dup2(fd[WRITE_END], STDOUT_FILENO);
	close(fd[WRITE_END]);
	flags = ft_split(argv[2], ' ');
	command = ft_env_path(env, argv[2], flags);
	execve(command, flags, env);
	ft_free_matrix(flags);
}

void	ft_bastards(int *fd, char **argv, char **env, int fd2)
{
	char	**flags;
	char	*command;

	if (!*argv[3])
		return ;
	dup2(fd[READ_END], STDIN_FILENO);
	close(fd[READ_END]);
	dup2(fd2, STDOUT_FILENO);
	flags = ft_split(argv[3], ' ');
	command = ft_env_path(env, argv[3], flags);
	printf("HOLA2\n");
	execve(command, flags, env);
	printf("HOLA3\n");
	ft_free_matrix(flags);
}

int	ft_pipe(char **argv, char **env, int fd2)
{
	int	fd1[2];
	int	pid;

	pipe(fd1);
	pid = fork();
	if (pid == 0)
		ft_frst_child(fd1, argv, env);
	else
	{
		close(fd1[WRITE_END]);
		pid = fork();
		if (pid == 0)
			ft_bastards(fd1, argv, env, fd2);
		else
			close(fd1[READ_END]);
	}
	return (0);
}
