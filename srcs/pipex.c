/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 10:35:00 by agallipo          #+#    #+#             */
/*   Updated: 2022/02/07 13:30:59 by agallipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int  main(void)
{
	int fd1[2]; //indice 0 extremo de lectura, 1 de escritura;
	int fd2; //corresponde a un archivo final
	int status; //para el wait que haace el padre
	int pid; //identificador de los procesos hijos 

	/*if (argc != 5)
	{
		printf("Ivalid arguments"	);
		return (1);
	}*/
	pipe(fd1);  // creara un pipe y devuelve el array con los fds correspondientes
	pid = fork(); //devuelve el pid
	if (pid == 0) // se esta ejecutando el hijo el ls -l
	{
		close(fd1[0]); //cierra el extremo de lectura, solo necesita escribir
		dup2(fd1[1], STDOUT_FILENO);//en vez de escribir en el out, escribe en el extremo de escritura de pipe
		close(fd1[1]);
		execlp("/bin/ls", "ls", "-l", NULL); //ls y null para no poner mas argumentos
	}
	else
	{
		close(fd1[1]); //como el padre ha cerrado el extremo de escritura, el hijo solo hereda el de lectura
		pid = fork(); //crea el segundo hijo
		 if (pid == 0) // el hijo ejecuta wc
		 {
			 fd2 = open("./files/file.txt", O_WRONLY);
			 dup2(fd1[0], STDIN_FILENO); //lea en vez de en el stdin, en el file 
			 close(fd1[0]);
			 dup2(fd2, STDOUT_FILENO);
			 execlp("/usr/bin/wc", "wc", NULL);
		 }
		 else
			 close(fd1[0]); //cerrar en el padre la lectura
	}
	wait(&status); //wait para cada hijo(?)
	wait(&status);

	return (0);
	
}

