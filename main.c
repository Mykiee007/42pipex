/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:10:09 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/02/26 14:48:20 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


char *get_path(char **envp)
{
	
	int i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return envp[i] + 5; // skip "PATH="
		i++;
	}
	return NULL; // PATH not found
}

static void in_envp(char **envp)
{
	int i = 0;

	while(envp[i])
	{
		ft_printf("%s\n", envp[i]);
		i++;
	}
}

int main(int argc, char **argv, char **envp)
{
	char *path = get_path(envp);
	if (path) {
		ft_printf("PATH: %s\n", path);
		ft_printf("inside the envp:\n" );
		in_envp(envp);
	} else {
		ft_printf("PATH not found in environment variables.\n");
		return 1;
	}
	if (argc != 5) {
		ft_printf("Usage: %s infile cmd1 cmd2 outfile\n", argv[0]);
		return 1;
	}
	return 0;
}


// this talks about communicating with pipes
/*int main(int argc, char **argv)
{
	printf("argc value %d\n", argc);
	printf("argv value %s\n", argv[1]);
	int fd[2];
	if (pipe(fd) == -1) {
		printf("error in opening the pipe");
		return 1;
	}
	int id = fork();
	if (id == -1)
	{
		printf("problem with fork\n");
		return 4;
	}
	if (id == 0) {
		int x;
		close(fd[0]);
		printf("input an number:");
		scanf("%d", &x);
		if (write(fd[1], &x, sizeof(int)) == -1)
		{
			printf("error accured in write");
			return 2;
		}
		close(fd[1]);
	} else {
		int y;
		close(fd[1]);
		if (read(fd[0], &y, sizeof(int)) == -1)
		{
			printf("error accured in read");
			return 3;
		}
		y = y*3;
		close(fd[0]);
		printf("Recieved from child process: %d\n",y);
	}

	return 0;
}*/


// this is similar to pipex method but much simpier
/*
int main(int argc, char **argv)
{
	printf("argc value %d\n", argc);
	printf("argv value %s\n", argv[1]);
	int fd[2];
	if (pipe(fd) == -1)
	{
		return 1;
	}
	int pid1 = fork();
	if (pid1 < 0)
	{
		return 2;
	}
	if (pid1 == 0)
	{
		//child process for 1st command
		dup2(fd[1],1);
		close(fd[0]);
		close(fd[1]);
		execlp("ping", "ping", "-c", "5", "google.com", NULL);
	}
	int pid2 = fork();
	if (pid2 < 0)
	{
		return 3;
	}
	if (pid2 == 0)
	{
		// child process for 2nd command
		dup2(fd[0],0);
		close(fd[0]);
		close(fd[1]);
		execlp("grep", "grep", "rtt", NULL);
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1,NULL,0);
	waitpid(pid2,NULL,0);


	return 0;
}
*/

// this for fork and pipe  knowing.
/*int main(int argc, char **argv)
{
	printf("argc value %d\n", argc);
	printf("argv value %s\n", argv[1]);
	int arr[] = { 1, 2, 3};
	int start, end;
	int arrSize = sizeof(arr)/sizeof(int);
	int fd[2];
	if (pipe(fd) == -1)
	{
		return 0;
	}
	int id = fork();
	if (id == -1)
	{
		return 0;
	}
	if (id == 0)
	{
		start = 0;
		end = arrSize/2;

	}
	else
	{
		start = arrSize/2;
		end = arrSize;
	}

	int sum = 0;
	int i = start;
	while(i < end)
	{
		sum = sum + arr[i];
		i++;
	}
	printf("Calculated partial sum: %d\n", sum);
	if (id == 0)
	{
		close(fd[0]);
		write(fd[1],&sum, sizeof(sum));
		close(fd[1]);	
	} else {
		int sumFromChild;
		close(fd[1]);
		read(fd[0], &sumFromChild,sizeof(sumFromChild));
		close(fd[0]);

		int totalSum = sum + sumFromChild;
		printf("total sum %d\n", totalSum);
		wait(NULL);
	}
    return (0);
}*/
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