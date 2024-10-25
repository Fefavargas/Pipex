/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefa <fefa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:11:44 by marvin            #+#    #+#             */
/*   Updated: 2024/10/24 20:44:29 by fefa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <fcntl.h> // open()
# include <stdlib.h> // exit()
# include <unistd.h> //fork(), pipe(),
# include <stdio.h> // STOUT_FILENO
# include <sys/wait.h> //waitpid

void	execute(char *argv, char **envp);

#endif