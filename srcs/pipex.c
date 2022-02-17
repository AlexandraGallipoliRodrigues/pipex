/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <agallipo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:01:50 by agallipo          #+#    #+#             */
/*   Updated: 2022/02/17 13:40:48 by agallipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/*void ft_leaks()
{
	system("leaks -q pipex");
}*/
int	main(int argc, char **argv, char **env)
{
	int	fd2;

	if (argc != 5)
	{
		printf("Invalid arguments\n");
		return (-1);
	}
	fd2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC | O_APPEND,
			S_IRWXU, 0777);
	if (fd2 < 0)
		printf("pipex: Error file: %s\n", argv[4]);
	ft_pipe(argv, env, fd2);
	return (0);
}
