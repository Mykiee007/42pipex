/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:10:09 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/03/16 14:03:39 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_px(t_pipex *px)
{
	px->status = 0;
	px->fd[0] = -1;
	px->fd[1] = -1;
	px->infile = -1;
	px->outfile = -1;
	px->pid1 = -1;
	px->pid2 = -1;
	px->cmd1_args = NULL;
	px->cmd2_args = NULL;
	px->exec_path1 = NULL;
	px->exec_path2 = NULL;
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
