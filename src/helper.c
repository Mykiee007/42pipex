/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:10:09 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/03/11 13:28:27 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	ft_input_error(t_pipex *px ,int argc, char **argv)
{
	if (argc != 5)
		ft_printf("Usage: %s infile cmd1 cmd2 outfile\n", argv[0]);
	if (px->infile == -1)
		ft_printf("Error opening infile: %s\n", strerror(errno));
	if (px->outfile == -1)
		ft_printf("Error opening outfile: %s\n", strerror(errno));
	if (px->fd[0] == -1 || px->fd[1] == -1)
		ft_printf("Error creating pipe: %s\n", strerror(errno));
	if (!px->cmd1_args || !px->cmd1_args[0])
		ft_printf("Error: cmd1_args is NULL\n");
	if (!px->cmd2_args || !px->cmd2_args[0])
		ft_printf("Error: cmd2_args is NULL\n");
	if (px->exec_path1 == NULL)
		ft_printf("Error: exec_path1 is NULL\n");
	if (px->exec_path2 == NULL)
		ft_printf("Error: exec_path2 is NULL\n");
}

void	close_all(t_pipex *px)
{
	close(px->fd[0]);
	close(px->fd[1]);
	close(px->infile);
	close(px->outfile);
}
