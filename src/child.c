/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 13:53:59 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/03/11 11:57:38 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child1(t_pipex *px, char **envp)
{
	dup2(px->infile, STDIN_FILENO);
	dup2(px->fd[1], STDOUT_FILENO);
	close(px->fd[0]);
	close(px->fd[1]);
	close(px->infile);
	close(px->outfile);
	execve(px->exec_path1, px->cmd1_args, envp);
}

void	child2(t_pipex *px, char **envp)
{
	dup2(px->fd[0], STDIN_FILENO);
	dup2(px->outfile, STDOUT_FILENO);
	close(px->fd[0]);
	close(px->fd[1]);
	close(px->infile);
	close(px->outfile);
	execve(px->exec_path2, px->cmd2_args, envp);
}