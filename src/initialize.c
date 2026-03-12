/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 11:58:22 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/03/12 12:48:08 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	init_files(t_pipex *px, char **argv)
{
	px->infile = open(argv[1], O_RDONLY);
	if (px->infile < 0)
		return (-1);
	px->outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (px->outfile < 0)
		return (-1);
	return (0);
}

int	init_cmds(t_pipex *px, char **argv, char **envp)
{
	px->cmd1_args = ft_split(argv[2], ' ');
	px->cmd2_args = ft_split(argv[3], ' ');
	if (!px->cmd1_args || !px->cmd2_args
		|| !px->cmd1_args[0] || !px->cmd2_args[0])
		return (-1);
	px->exec_path1 = get_exec_path(px->cmd1_args[0], envp);
	px->exec_path2 = get_exec_path(px->cmd2_args[0], envp);
	if (!px->exec_path1 || !px->exec_path2)
		return (-1);
	return (0);
}
