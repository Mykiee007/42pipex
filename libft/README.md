*This project has been created as part of the 42 curriculum by mvelasqu.*

# Libft

---

## Description
Libft is the first project of the 42 curriculum.  
Its purpose is to recreate a small, custom standard C library by re-implementing a set of essential standard functions, as well as additional utility functions that will be used in later projects.

The goal of this project is to:
- Understand low-level memory manipulation  
- Learn how to organize a reusable C library  
- Practice writing clean, modular, norm-compliant C code  
- Build a foundation for all future 42 projects

This library compiles into `libft.a` using the provided `Makefile`.

---

## 🔧 Instructions

### ✔️ Compilation
To compile the library:
```bash
make
```

To clean object files:
```bash
make clean
```

To remove objects + library:
```bash
make fclean
```

To recompile from scratch:
```bash
make re
```

If you want to compile a main.c that uses libft,
place your main.c in the same directory where libft.a and libft.h are located.
```bash
cc -Wall -Wextra -Werror main.c libft.a
```

And in your source files:
```bash
#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"
```

## Library Overview

Libft contains re-implemented standard C functions + additional utilities.

### Part 1 — Libc Functions

Character checks
- ft_isalpha
- ft_isdigit
- ft_isalnum
- ft_isascii
- ft_isprint

Character case
- ft_toupper
- ft_tolower

String length & copy
- ft_strlen
- ft_strlcpy
- ft_strlcat

Memory manipulation
- ft_memset
- ft_bzero
- ft_memcpy
- ft_memmove
- ft_memchr
- ft_memcmp

String search / compare
- ft_strchr
- ft_strrchr
- ft_strncmp
- ft_strnstr

Conversion
- ft_atoi

Memory allocation / duplication
- ft_calloc
- ft_strdup

### Part 2 — Additional Functions

String creation & transformation
- ft_substr
- ft_strjoin
- ft_strtrim
- ft_split
- ft_strmapi
- ft_striteri

Number ↔ string
- ft_itoa

File descriptor output
- ft_putchar_fd
- ft_putstr_fd
- ft_putendl_fd
- ft_putnbr_fd

### Bonus (if enabled)

Linked list utilities using t_list:
- ft_lstnew - Returns a new node.
- ft_lstadd_front - Adds the node ’new’ at the beginning of the list.
- ft_lstsize - Counts the number of nodes in the list.
- ft_lstlast - Returns the last node of the list.
- ft_lstadd_back - Adds the node ’new’ at the end of the list.
- ft_lstdelone - Takes a node as parameter and frees its content using the function ’del’. 
- ft_lstclear - Deletes and frees the given node and all its successors, using the function ’del’ and free(3).
- ft_lstiter - Iterates through the list ’lst’ and applies the function ’f’ to the content of each node.
- ft_lstmap - Iterates through the list ’lst’, applies the function ’f’ to each node’s content, and creates a new list resulting of the successive applications of the function ’f’.

### ft_printf

A custom implementation of the standard printf function.

ft_printf – Prints formatted output to standard output, supporting flags, width, precision, and specifiers such as %c, %s, %d, %i, %u, %x, %X, %p, and %%

### get_next_line

A function that reads input line by line from a file descriptor.

get_next_line – Reads and returns one line at a time from a file descriptor, handling buffering internally and preserving leftover data between calls

## Resources

- Classic references used for this project:
- man pages for libc functions
- The C Programming Language (K&R)
- Tutorials and documentation on memory management and pointers
- 42 subject PDF

## Use of AI

- AI (ChatGPT) was used only for:
- Clarifying C concepts
- Understanding segmentation faults / memory models
- Getting guidance on Makefile structure
- No code was directly copied or inserted into the project, following 42’s rules.
