/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:10:09 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/03/12 13:29:04 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_px(t_pipex *px)
{
	px-> fd[0] = 0;
	px-> fd[1] = 0;
	px-> infile = 0;
	px-> outfile = 0;
	px-> pid1 = 0;
	px-> pid2 = 0;
	px-> cmd1_args = NULL;
	px-> cmd2_args = NULL;
	px-> exec_path1 = NULL;
	px-> exec_path2 = NULL;
}

char	*ft_join3(char *str1, char*str2, char *str3)
{
	char	*tmp;
	char	*result;

	if (!str1)
		str1 = "";
	if (!str2)
		str2 = "";
	if (!str3)
		str3 = "";
	tmp = ft_strjoin(str1, str2);
	if (!tmp)
		return (NULL);
	result = ft_strjoin(tmp, str3);
	free (tmp);
	return (result);
}

void	ft_input_error(t_pipex *px)
{
	if (px->infile == -1 || px->outfile == -1)
		exit(1);
	if (!px->cmd1_args || !px->cmd1_args[0] || !px->cmd2_args || !px->cmd2_args[0])
		exit(1);
	if (px->exec_path1 == NULL || px->exec_path2 == NULL)
		exit (1);
}

void	close_all(t_pipex *px)
{
	close(px->fd[0]);
	close(px->fd[1]);
	close(px->infile);
	close(px->outfile);
}

void	free_all(t_pipex *px)
{
	ft_free_split (px->cmd1_args);
	ft_free_split (px->cmd2_args);
	free (px->exec_path1);
	free (px-> exec_path2);
}
