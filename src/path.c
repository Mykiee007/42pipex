/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 11:55:42 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/03/13 10:33:55 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char **envp)
{
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

char	*find_in_path(char **paths, char *cmd)
{
	char	*full_cmd;
	int		i;

	i = 0;
	while (paths[i])
	{
		full_cmd = ft_join3(paths[i], "/", cmd);
		if (!full_cmd)
			return (NULL);
		if (access(full_cmd, X_OK) == 0)
			return (full_cmd);
		free(full_cmd);
		i++;
	}
	return (NULL);
}

char	*get_exec_path(char *cmd, char **envp)
{
	char	**paths;
	char	*exec_path;
	char	*path;

	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
		perror("Error");
		return (NULL);
	}
	path = get_path(envp);
	paths = ft_split(path, ':');
	if (!paths)
		return (NULL);
	exec_path = find_in_path(paths, cmd);
	if (access(exec_path, X_OK) == 0)
			return (ft_free_split(paths), exec_path);
	ft_free_split(paths);
	return (NULL);
}
