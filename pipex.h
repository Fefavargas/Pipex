/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:11:44 by marvin            #+#    #+#             */
/*   Updated: 2024/10/23 11:54:18 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <fcntl.h> // open()
# include <stdlib.h> // exit()
# include <unistd.h> //fork(), pipe(),
# include <stdio.h> // STOUT_FILENO

void	execute(char *argv, char **envp);

#endif