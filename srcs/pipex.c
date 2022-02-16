/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <agallipo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:01:50 by agallipo          #+#    #+#             */
/*   Updated: 2022/02/16 17:48:54 by agallipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/*void ft_leaks()
{
	system("leaks -q pipex");
}*/
int	main(int argc, char **argv, char **env)
{
	int	fd;
	int	fd2;

	if (argc < 4)
		return (-1);
	fd = open(argv[1], O_RDONLY);
	fd2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (fd < 0)
	{
		printf("pipex: Error file: %s\n", argv[1]);
		exit (0);
	}
	if (fd2 < 0)
		printf("pipex: Error file: %s\n", argv[4]);
	ft_pipe(argv, env, fd, fd2);
	return (0);
}
