/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 07:31:15 by marvin            #+#    #+#             */
/*   Updated: 2024/10/23 11:55:16 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_array(char **paths)
{
	int	i;

	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
}

char	*get_path(char *cmd, char **envp)
{
	int		i;
	char	**paths;
	char	*path;
	char	*part_path;

	i = 0;
	while (ft_strncmp(envp[i], "PATH", 4))
		i++;
	paths = ft_split(envp[i + 5], ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0)
		{
			free_array(paths);
			return (path);
		}
		free(path);
		i++;
	}
	free_array(paths);
	return (0);
}

void	execute(char *argv, char **envp)
{
	char	*path;
	char	**cmd;

	cmd = ft_split(argv, ' ');
	path = get_path(cmd[0], envp);
	if (!path)
	{
		free_array(cmd);
		ft_putstr_fd("Command not found", 2);
		return ;
	}
	if (execve(path, cmd, envp) == -1)
		ft_putstr_fd("Command not found", 2);
	free(path);
	free_array(cmd);
}
