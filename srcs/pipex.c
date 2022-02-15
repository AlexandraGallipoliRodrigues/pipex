/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <agallipo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:01:50 by agallipo          #+#    #+#             */
/*   Updated: 2022/02/15 13:26:11 by agallipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int main(int argc, char **argv, char **env)
{
	int	fd;
	int	fd2;

	if (argc < 4)
		return (-1);
	fd = open(argv[1], O_RDONLY);
	fd2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (fd < 0 || fd2 < 0)
		return (-1);
	argc = 0;
	ft_pipe(argv, env, fd, fd2);
	//system("leaks -q pipex");
	return (0);
}
