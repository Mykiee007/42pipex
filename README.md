*This project has been created as part of the 42 curriculum by mvelasqu.*

# Description

### Overiew

### Target

The output of the program should be the same as when you use:

```
< infile ls -l | wc -l > outfile
```

Call the program after doing "make" as follows:

```
/pipex file1 cmd1 cmd2 file2
```

### Extranal Functions

First encounters with these functions

| NAME | PROTOTYPE | DESCRIPTION | LIBRARY |
| :---: | :---: | :--- | :---: |
| perror | void perror(const char *s) | Function designed to print a descriptive error message to the standard error stream (stderr).</br>Add errno.h for standard error printing | <stdio.h> | 
| strerror | char *strerror(int errnum) | Function returns a string describing the meaning of an error code. Error code comes from errno | <string.h> |
| access | int access(char const *path, int mode) | Function that determine whether the calling process has access to a specified file or directory | <unistd.h> |
| dup | int dup(int filedes) | Duplicate a copy of a file descriptor | <unistd.h> |
| dup2 | int dup(int filedes, int filedes2) | Same as dup, but instead of using the lowest-numbered unused file descriptor, it uses the descriptor number specified by the user | <unistd.h> |
| exit | void exit(int status) | Function used to terminate/exit the calling process immediately. | <stdlib.h> |
| fork | pid_t fork(void) | Create a child process. fork() splits one running program into two independent programs starting from the same line. On success: parents get positive number and child gets 0. On failure: negative number.  | <unistd.h> |
| wait | pid_t wait(int *status) |The primary purpose is for the parent process to collect the exit status of its child processes and allow the system to release the resources associated with the child. | <sys/wait.h>|
| waitpid | pid_t waitpid(pid_t pid, int *status, int options) |  wait for state changes in child of the calling process, and obtain information about the child whose state has changed.   If a child has already changed state, then these calls return immediately.  Otherwise, they block until either a child changes state or a signal handler interrupts the call  | <sys/wait.h> |
| unlink | int unlink(const char *path) | The path to the file or symbolic link you want to remove | <unistd.h> |
| pipe | int pipe(int pipefd[2]) | This connects two process. its a unidirectional data channel that can be used for interprocess communication.  The array pipefd is used to return two file descriptors referring to the ends of the pipe. pipefd[0] refers to the read end of the pipe.  pipefd[1] refers to the write end of the pipe.  Data written to the write end of the pipe is buffered by the kernel until it is read from the read end of the pipe. | <unistd.h> |
| execve | int execve(const char *path/filename, char *const argv[], char *const envp[]) | this function loads a new program into a process memory. The exisiting process is discarded. The newly process gets all the new stak data & heap. since it replaces the process's memory, the return value is always -1. | <unistd.h> |

### Other Notes

| ITEM | DESCRIPTION | LIBRARY |
| :--- | :--- | :-- |
| STDIN_FILENO | a standard symbolice constant that signifies standard input or 0 | <unistd.h> |
| STDOUT_FILENE | a symbolic constant that signifies standard output or 1 | <unistd.h>|

# Instruction

Compile the program using make, you will have an executable program:
```
./pipex
```


# Resources



# Notes

These is a unfiltered and un edited write up of a developer as he progresses. 