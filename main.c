/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:10:09 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/03/13 10:02:46 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	px;

	if (argc != 5)
		return (ft_putstr_fd("Usage: ./pipex infile cmd1 cmd2 outfile\n", 2), 1);
	if (init_files(&px, argv) == -1)
		return (1);
	if (init_cmds(&px, argv, envp) == -1)
		return (ft_input_error(&px), 1);
	if (pipe(px.fd) == -1)
		return (perror("pipe"), close_all(&px), 1);
	px.pid1 = fork();
	if (px.pid1 == 0)
		child1(&px, envp);
	px.pid2 = fork();
	if (px.pid2 == 0)
		child2(&px, envp);
	close_all(&px);
	waitpid(px.pid1, NULL, 0);
	waitpid(px.pid2, NULL, 0);
	return (0);
}