/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:10:42 by marvin            #+#    #+#             */
/*   Updated: 2024/10/30 15:51:55 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child(char **argv, char **envp, int *pipefd)
{
	int	fd_in;

	fd_in = open(argv[1], O_RDONLY);
	if (fd_in == -1)
		error(argv[1]);
	dup2(fd_in, STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	close(fd_in);
	close(pipefd[0]);
	close(pipefd[1]);
	execute(argv[2], envp);
}

void	parent(char **argv, char **envp, int *pipefd)
{
	int	fd_out;

	fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd_out == -1)
		error(argv[4]);
	dup2(pipefd[0], STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	close(fd_out);
	close(pipefd[0]);
	close(pipefd[1]);
	execute(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	int		pipefd[2];

	if (argc != 5)
	{
		ft_putstr_fd("\033[31mError: Bad arguments\n", 2);
		ft_putstr_fd("Ex: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 1);
		exit(SIGQUIT);
	}
	if (pipe(pipefd) == -1)
		error("");
	pid = fork();
	if (pid == -1)
		error("");
	if (pid == 0)
		child(argv, envp, pipefd);
	waitpid(pid, NULL, 0);
	parent(argv, envp, pipefd);
}
