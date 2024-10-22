/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:10:42 by marvin            #+#    #+#             */
/*   Updated: 2024/10/21 17:10:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"


//# include <string.h>
//# include <sys/wait.h>


void	child(char **argv, char **envp, int *pipefd)
{
	int	fd_in;

	fd_in  = open(argv[1], O_RDONLY);
	if (fd_in == -1)
		exit(-1);
	dup2(pipefd[1], STDOUT_FILENO); // não faz sentido
	dup2(fd_in, STDIN_FILENO); //faz sentido
	close(pipefd[0]); //não faz sentido
	execute(argv[2], envp);
}

void	parent(char **argv, char **envp, int *pipefd)
{
	int	fd_out;

	fd_out  = open(argv[4], O_WRONLY);
	if (fd_out == -1)
		exit(-1);
	dup2(pipefd[0], STDOUT_FILENO); // não faz sentido
	dup2(fd_out, STDIN_FILENO); //faz sentido
	close(pipefd[1]); //não faz sentido
	execute(argv[3], envp);
}

int main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	int		pipefd[2];
	/*
	if (argc != 5) 
	    return (0);
	if (pipe(pipefd) == -1)
		exit(-1);
	pid = fork();
	if (pid == -1)
		exit(-1);
	if (pid == 0)
		child(argv, envp, pipefd);
	parent(argv, envp, pipefd);*/
	
	int i=-1;
	while (envp[++i])
		printf("%s\n", envp[i]);
}