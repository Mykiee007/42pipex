/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 13:53:59 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/03/12 12:48:23 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child1(t_pipex *px, char **envp)
{
	if (dup2(px->infile, STDIN_FILENO) == -1
		|| dup2(px->fd[1], STDOUT_FILENO) == -1)
	{
		perror("Error dup2 in Child 1");
		close_all(px);
		exit(EXIT_FAILURE);
	}
	close_all(px);
	if (execve(px->exec_path1, px->cmd1_args, envp) == -1)
	{
		perror("Error execve in Child 1");
		exit(EXIT_FAILURE);
	}
}

void	child2(t_pipex *px, char **envp)
{
	if (dup2(px->fd[0], STDIN_FILENO) == -1
		|| dup2(px->outfile, STDOUT_FILENO) == -1)
	{
		perror("Error dup2 in Child 2");
		close_all(px);
		exit(EXIT_FAILURE);
	}
	close_all(px);
	if (execve(px->exec_path2, px->cmd2_args, envp) == -1)
	{
		perror("Error execve in Child 2");
		exit(EXIT_FAILURE);
	}
}
