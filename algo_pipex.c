#include "pipex.h"

int main(int argc, char **argv)
{
	int fd[2];
	int i;
	int in_fd = open(argv[1],O_RDONLY);
	int out_fd = open(argv[argc],O_RDWR);

	if (access(argv[1], R_OK & W_OK) == -1) {
		printf("Error access infile: %s\n", strerror(errno));
		return 3;
	}
	if (access(argv[argc], R_OK & W_OK) == -1) {
		printf("Error access outfile: %s\n", strerror(errno));
		return 4;
	}
	if (in_fd == -1) {
		printf("Error open infile: %s\n", strerror(errno));
		return 5;		
	}
	if (out_fd == -1) {
		printf("Error open opening infile: %s\n", strerror(errno));
		return 6;		
	}
	int pid = fork();
	if (pid == -1) {
		printf("Error in fork: %s\n",strerror(errno));
		return 2;
	}
	if (argv[2] == "here_doc")
	{
		int cmd_n = argc - 4;
		int cmd_start = 3;
		int i = cmd_start;
		char *argvCmd;
		char *file;

		while (i != (cmd_n - 1))
		{
			if(pipe(fd) == -1){
				printf("Error in pipe: %s\n",strerror(errno));
				return 1;
			}
			int pid = fork();
			if (pid == -1) {
				printf("Error in fork: %s\n",strerror(errno));
				return 2;
			}
			int *tmp = ft_strjoin(argv[i]," ");
			file = ft_strjoin(tmp,argv[1]);
			free(tmp);
			argvCmd = ft_split(file,' ');
			free(file);
			cmd = ft_strjoin()
			if (!cmd) {
				printf("error in split: %s\n", strerror(errno));
				return 7;
			}

			if (pid == 0) {
				dup2(in_fd,0);
				if (i != cmd_n)
					dup2(fd[1],1);
				else
					dup2(out_fd, 1);
				close(in_fd);
				if (i != (cmd_n -1))
				{
					close(fd[0]);
					close(fd[1]);
				}
				close(out_fd);
				execve(cmd[0],cmd, 0);
			}

		}
	}
	else {
		int cmd_n = argc - 3;
		int cmd_start = 2;
	}
	return 0;
}