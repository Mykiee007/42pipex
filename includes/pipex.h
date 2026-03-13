/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:00:39 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/03/13 10:40:49 by mvelasqu         ###   ########.fr       */
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
	char	*exec_path1;
	char	*exec_path2;
}	t_pipex;

void	ft_print_split(char **split);
char	*get_path(char **envp);
char	*find_in_path(char **paths, char *cmd);
char	*ft_join3(char *str1, char*str2, char *str3);
char	*find_in_path(char **paths, char *cmd);
char	*get_exec_path(char *cmd, char **envp);
int		init_files(t_pipex *px, char **argv);
int		init_cmds(t_pipex *px, char **argv, char **envp);
int		init_cmd_args(t_pipex *px, char **argv);
void	child1(t_pipex *px, char **envp);
void	child2(t_pipex *px, char **envp);
void	ft_input_error(t_pipex *px);
void	close_all(t_pipex *px);
int		main(int argc, char **argv, char **envp);

#endif