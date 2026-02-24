/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:10:09 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/02/24 12:55:53 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv)
{
	int fd = open(argv[1], O_RDWR)
	int fd[1];

	



    return (0);
}
/*
Strategy
	Open infile
	Create pipe
	fork
		child 1:
		redirect infile → stdin
		redirect pipe write → stdout
		execve cmd1
	parent:
		fork again
			child 2:
				redirect pipe read → stdin
				redirect outfile → stdout
				execve cmd2
	wait for children

strategy for bonus
in_fd = open(infile)
out_fd = open(outfile, TRUNC)
for each command i = 0..n-1:
	if i != n-1: pipe(p)
	pid = fork()
	child:
		dup2(in_fd, 0)
		if i != n-1: dup2(p[1], 1)
		else: dup2(out_fd, 1)
		close in_fd
		if i != n-1: close p[0], close p[1]
		close out_fd
		execve(cmd[i])
	parent:
		close in_fd
		if i != n-1:
		close p[1]
		in_fd = p[0]
		close out_fd (and in_fd if still open)
wait for all children (N times)
*/