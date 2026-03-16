/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 11:58:22 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/03/16 13:44:50 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	init_files(t_pipex *px, char **argv)
{
	px->infile = open(argv[1], O_RDONLY);
	if (px->infile == -1)
		perror("infile");
	px->outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (px->outfile == -1)
		perror("outfile");
	if (px->infile < 0 || px->outfile < 0)
		return (-1);
	return (0);
}

int	init_cmd_args(t_pipex *px, char **argv)
{
	px->cmd1_args = ft_split(argv[2], ' ');
	if (!px->cmd1_args || !px->cmd1_args[0])
	{
		ft_putstr_fd(argv[2], 2);
		ft_putstr_fd(": command not found\n", 2);
	}
	px->cmd2_args = ft_split(argv[3], ' ');
	if (!px->cmd2_args || !px->cmd2_args[0])
	{
		ft_putstr_fd(argv[3], 2);
		ft_putstr_fd(": command not found\n", 2);
	}
	if (!px->cmd1_args || !px->cmd1_args[0]
		|| !px->cmd2_args || !px->cmd2_args[0])
		return (-1);
	return (0);
}

int	init_cmds(t_pipex *px, char **argv, char **envp)
{
	if (init_cmd_args(px, argv) == -1)
		return (-1);
	px->exec_path1 = get_exec_path(px->cmd1_args[0], envp);
	px->exec_path2 = get_exec_path(px->cmd2_args[0], envp);
	return (0);
}
