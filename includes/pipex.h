/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 10:41:20 by agallipo          #+#    #+#             */
/*   Updated: 2022/02/09 11:58:31 by agallipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //dup2
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
char	*ft_command_env(char **env);
char	**ft_find_command(char **env);
#endif
