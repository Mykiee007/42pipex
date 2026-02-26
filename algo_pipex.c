#include "pipex.h"

static void free_split(char **split)
{
	int i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

char *get_exec_path(char *cmd, char *path)
{
	char **paths = ft_split(path, ':');
	int i = 0;
	while (paths[i])
	{
		char *full_path = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin(full_path, cmd);
		if (access(full_path, X_OK) == 0)
		{
			free_split(paths);
			return full_path;
		}
		free(full_path);
		i++;
	}
	free_split(paths);
	return NULL; // command not found in any PATH directory
}

int algo_pipex(int argc, char **argv, char **envp)
{
    int fd[2];
    pipe(fd);
	int infile = open("infile", O_RDONLY);
	int outfile = open("outfile", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	char **cmd1_args = ft_split(argv[2], ' ');
	char **cmd2_args = ft_split(argv[3], ' ');
	char *path = get_path(envp);
	char *exec_path1 = get_exec_path(cmd1_args[0], path);
	char *exec_path2 = get_exec_path(cmd2_args[0], path);
	if (argc != 5)
	{
		printf("Usage: %s infile cmd1 cmd2 outfile\n", argv[0]);
		return 1;
	}
    if (fork() == 0)
    {
		dup2(infile, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
        close(infile);
        close(fd[1]);

		execve(exec_path1, cmd1_args, envp);
    }

    if (fork() == 0)
    {
		dup2(fd[0], STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        close(outfile);

		execve(exec_path2, cmd2_args, envp);
    }

    // parent closes pipe
    close(fd[0]);
    close(fd[1]);
	close(infile);
	close(outfile);

    wait(NULL);
    wait(NULL);
	return 1;
}