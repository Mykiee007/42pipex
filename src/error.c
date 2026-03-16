/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 13:48:33 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/03/16 13:59:45 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_input_error(t_pipex *px)
{
	close_all(px);
	free_all(px);
}

void	close_all(t_pipex *px)
{
	if (px->fd[0] != -1)
	{
		close(px->fd[0]);
		px->fd[0] = -1;
	}
	if (px->fd[1] != -1)
	{
		close(px->fd[1]);
		px->fd[1] = -1;
	}
	if (px->infile != -1)
	{
		close(px->infile);
		px->infile = -1;
	}
	if (px->outfile != -1)
	{
		close(px->outfile);
		px->outfile = -1;
	}
}

void	free_all(t_pipex *px)
{
	if (px->cmd1_args)
	{
		ft_free_split(px->cmd1_args);
		px->cmd1_args = NULL;
	}
	if (px->cmd2_args)
	{
		ft_free_split(px->cmd2_args);
		px->cmd2_args = NULL;
	}
	if (px->exec_path1)
	{
		free(px->exec_path1);
		px->exec_path1 = NULL;
	}
	if (px->exec_path2)
	{
		free(px->exec_path2);
		px->exec_path2 = NULL;
	}
}
