/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:00:39 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/03/09 13:58:57 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include "ft_printf.h"
# include <errno.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>

typedef struct s_pipex
{
	int		fd[2];
	int		infile;
	int		outfile;
	pid_t	pid1;
	pid_t	pid2;
	char	**cmd1_args;
	char	**cmd2_args;
	char	*path;
	char	*exec_path1;
	char	*exec_path2;
}	t_pipex;

char	*get_path(char **envp);
char	*find_in_path(char **paths, char *cmd);
char	*ft_join3(char *str1, char*str2, char *str3);
char	*find_in_path(char **paths, char *cmd);
char	*get_exec_path(char *cmd, char **envp);
void	close_all(t_pipex *px);
int		main(int argc, char **argv, char **envp);

#endif