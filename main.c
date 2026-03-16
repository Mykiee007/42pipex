/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:10:09 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/03/16 14:03:34 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	px;

	init_px (&px);
	if (argc != 5)
		return (perror("Usage: ./pipex infile cmd1 cmd2 outfile\n"), 1);
	if (init_files(&px, argv) == -1 || init_cmds(&px, argv, envp) == -1)
		return (ft_input_error(&px), 1);
	if (pipe(px.fd) == -1)
		return (perror("pipe"), ft_input_error(&px), 1);
	px.pid1 = fork();
	if (px.pid1 == -1)
		return (perror("fork"), ft_input_error(&px), 1);
	if (px.pid1 == 0)
		child1(&px, envp);
	px.pid2 = fork();
	if (px.pid2 == -1)
		return (perror("fork"), ft_input_error(&px), 1);
	if (px.pid2 == 0)
		child2(&px, envp);
	ft_input_error(&px);
	waitpid(px.pid1, NULL, 0);
	waitpid(px.pid2, &px.status, 0);
	if (WIFEXITED(px.status))
		return (WEXITSTATUS(px.status));
	return (1);
}
