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

- perror - function designed to print a descriptive error message to the standard error stream (stderr). - <stdio.h>
- errno - a external integer, a number/error code containing the corresponding error message - <errno.h>
- strerror -  function returns a string describing the meaning of an error code. - <string.h>
- access - function that determine whether the calling process has access to a specified file or directory. <unistd.h>
- dup - duplicate a copy of a file descriptor <unistd.h>
- dup2 - same as dup, but instead of using the lowest-numbered unused file descriptor, it uses the descriptor number specified by the user. <unistd.h>
- **execve - executes the program pointed to by filename.**
- exit -  function used to terminate the calling process. <stdlib.h>
- fork - 
- pipe - 
- unlick -
- wait - 
- waitpid -

# Instruction

Compile the program using make, you will have an executable program:
```
./pipex
```


# Resources



# Notes

These is a unfiltered and un edited write up of a developer as he progresses. 