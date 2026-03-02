/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 14:58:00 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/03/02 15:29:41 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
	int fd[2];
	pipe(fd);
	int pid1 = fork();
	int pid2 = fork();

	if(pid1 < 0)
		return 1;
	if(pid2 < 0)
		return 1;
	if(pid1 == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		write(1,"HELLO FROM PIPE\n", 16);
		exit(0);
	}
	if(pid2 == 0)
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		char buffer[17];
		read(0, buffer, 16);
		buffer[16] = '\0';
		write(1, buffer, 16);
		exit(0);
	}
	close(fd[0]);
	close(fd[1]);
	wait(NULL);
	wait(NULL);
	return 0;
}