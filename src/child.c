/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 13:53:59 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/03/16 13:35:05 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child1(t_pipex *px, char **envp)
{
	if (!px->exec_path1)
	{
		ft_putstr_fd(px->cmd1_args[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		free_all(px);
		close_all(px);
		exit(127);
	}
	if (dup2(px->infile, STDIN_FILENO) == -1
		|| dup2(px->fd[1], STDOUT_FILENO) == -1)
	{
		perror("Error dup2 in Child 1");
		free_all(px);
		close_all(px);
		exit(1);
	}
	close_all(px);
	execve(px->exec_path1, px->cmd1_args, envp);
	perror(px->cmd1_args[0]);
	free_all(px);
	if (errno == EACCES)
		exit(126);
	exit(127);
}

void	child2(t_pipex *px, char **envp)
{
	if (!px->exec_path2)
	{
		ft_putstr_fd(px->cmd2_args[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		free_all(px);
		close_all(px);
		exit(127);
	}
	if (dup2(px->fd[0], STDIN_FILENO) == -1
		|| dup2(px->outfile, STDOUT_FILENO) == -1)
	{
		perror("Error dup2 in Child 2");
		free_all(px);
		close_all(px);
		exit(1);
	}
	close_all(px);
	execve(px->exec_path2, px->cmd2_args, envp);
	perror(px->cmd2_args[0]);
	free_all(px);
	if (errno == EACCES)
		exit(126);
	exit(127);
}
