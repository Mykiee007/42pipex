/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:10:09 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/02/19 13:22:04 by mvelasqu         ###   ########.fr       */
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
*/