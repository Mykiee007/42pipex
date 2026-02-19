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
| wait | | | |
| waitpid | | | |
| unlink | | | |
| pipe | | | |
| execve | | | |

# Instruction

Compile the program using make, you will have an executable program:
```
./pipex
```


# Resources



# Notes

These is a unfiltered and un edited write up of a developer as he progresses. 