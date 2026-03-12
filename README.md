*This project has been created as part of the 42 curriculum by mvelasqu.*

# Description

### Overiew

Pipex is a project that explores how the shell executes commands connected by pipes (|).

The goal is to recreate this behavior in C by using system calls such as fork, pipe, dup2, and execve. Through this project, I learned how processes communicate using file descriptors and how the shell locates and executes commands using environment variables like PATH.

Pipex provides a deeper understanding of Unix process management and exposes a different side of C programming that interacts directly with the operating system.

### Target

The output of the program should be the same as when you run the following command in the shell:

```
< infile ls -l | wc -l > outfile
```

Call the program after running make as follows:

```
./pipex file1 cmd1 cmd2 file2
```

### External Functions


First encounters with these functions

| NAME&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; | PROTOTYPE&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;   | DESCRIPTION | SUCCESS&nbsp;&nbsp;&nbsp; | FAILURE&nbsp;&nbsp;&nbsp; | LIBRARY&nbsp;&nbsp;&nbsp;&nbsp;  |
| :---: | :--- | :--- | :---: | :---: | :---: |
| perror | void perror(const char *s) | Prints a descriptive error message to stderr based on the current value of errno. | void | void | <stdio.h> | 
| strerror | char *strerror(int errnum) | Returns a string describing the error number given in errnum. | pointer to string | NULL | <string.h> |
| access | int access(char const *path, int mode) | Checks if the process has permission to access a file or directory. | 0 | -1 | <unistd.h> |
| dup | int dup(int filedes) | Creates a duplicate of a file descriptor. The new descriptor refers to the same open file description. | new fd | -1 | <unistd.h> |
| dup2 | int dup(int filedes, int filedes2) | Duplicates oldfd into newfd. If newfd exists, it is closed first. | new fd | -1 | <unistd.h> |
| exit | void exit(int status) | Function used to terminate/exit the calling process immediately. | no return | no return | <stdlib.h> |
| fork | pid_t fork(void) | Creates a child process. Execution continues in both parent and child. | parent: Child PID, child: 0 | -1 | <unistd.h> |
| wait | pid_t wait(int *status) | Suspends execution until one child process terminates. | child PID | -1 | <sys/wait.h>|
| waitpid | pid_t waitpid(pid_t pid, int *status, int options) |  Waits for a specific child process to change state.  | child PID | -1 | <sys/wait.h> |
| unlink | int unlink(const char *path) | The path to the file or symbolic link you want to remove.  | 0 | -1 | <unistd.h> |
| pipe | int pipe(int pipefd[2]) | Creates a unidirectional communication channel between processes. pipefd[0] read end, pipefd[1] write end. | 0 | -1 | <unistd.h> |
| execve | int execve(const char *path/filename, char *const argv[], char *const envp[]) | Replaces the current process with a new program. | no return | -1 | <unistd.h> |

### Other Notes

| ITEM | DESCRIPTION | LIBRARY |
| :--- | :--- | :-- |
| STDIN_FILENO | a standard symbolice constant that signifies standard input or 0 | <unistd.h> |
| STDOUT_FILENO | a symbolic constant that signifies standard output or 1 | <unistd.h>|
| 0 or EXIT_SUCCESS | in ``exit(int status)`` represents program has been successfully executed without encountering any error. |
| 1 or EXIT_FAILURE | in ``exit(int status)`` represents program has encountered an error and could be executed successfully.

### Concepts Learned

- Process creation with fork()
- Interprocess communication using pipe()
- File descriptor manipulation with dup2()
- Executing programs using execve()
- Parsing environment variables (PATH)
- Handling input/output redirection

# Instruction

Compile the program using ```make```. This will generate an executable:
```
./pipex
```
Run the program using:
```
./pipex infile cmd1 cmd2 outfile
```
Check ```outfile``` for the output.
if there is no ```outfile```, the program will create it. 

Notes:
- Make sure ```infile``` contains data.
- Existing data in ```outfile``` will be truncated when the program runs.

# Resources

- Man Pages: ```fork```, ```dup```, ```dup2```, ```wait```, ```waitpid```, ```access```, ```pipe```, ```execve```.
- YouTube tutorials about ```fork```, ```pipe```, and the ```exec``` family of functions
- AI for further clarifcaiton of new functions and concepts. 

# Notes

These is a unfiltered and un edited write up of a developer as he progresses. 

General Algorithim flow
```javascript
pipex infile cmd1 cmd2 outfile

declare fd[2];
create a pipe(fd); → check if success
open infile → check if success
open or create outfile → check if success
get cmd_path for cmd1 & cmd2 → include success
get cmd1_argv & cmd2_args → include success

	Child 1: → include success
	dup2(infile,STDIN_FILENO) → reads from infile then brings to pipe [0]
	dup2(fd[1],STDOUT_FILENO) → sets pipe[1] for output
	closed unused fds
	execute execve(cmd_path,argv,envp);

	Child 2: → include success
	dup2(fd[0],STDIN_FILENO) →takes output of Child 1 as input
	dup2(outfile,STDOUT_FILENO) → makes “outfile” the location of the output 
	closed unused fds
	execute execve(cmd_path,argv,envp);

close(fd[0]);
close(fd[1]);
close(infile);
close(outfile);
waitpid(child1,NULL,0);
waitpid(child2,NULL,0);
```