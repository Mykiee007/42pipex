# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/20 11:00:37 by mvelasqu          #+#    #+#              #
#    Updated: 2025/12/22 11:04:09 by mvelasqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Defining Variables
NAME = libft.a
CC = cc
IDIR = includes
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
PRINTF_DIR = ft_printf
GNL_DIR = get_next_line
INC = -I $(IDIR) -I $(PRINTF_DIR) -I $(GNL_DIR)

#FILES
SRCS = src/ft_atoi.c \
		src/ft_bzero.c \
		src/ft_calloc.c \
		src/ft_isalnum.c \
		src/ft_isalpha.c \
		src/ft_isascii.c \
		src/ft_isdigit.c \
		src/ft_isprint.c \
		src/ft_itoa.c \
		src/ft_memchr.c \
		src/ft_memcmp.c \
		src/ft_memcpy.c \
		src/ft_memmove.c \
		src/ft_memset.c \
		src/ft_putchar_fd.c \
		src/ft_putendl_fd.c \
		src/ft_putnbr_fd.c \
		src/ft_putstr_fd.c \
		src/ft_split.c \
		src/ft_strchr.c \
		src/ft_strdup.c \
		src/ft_striteri.c \
		src/ft_strjoin.c \
		src/ft_strlcat.c \
		src/ft_strlcpy.c \
		src/ft_strlen.c \
		src/ft_strmapi.c \
		src/ft_strncmp.c \
		src/ft_strnstr.c \
		src/ft_strrchr.c \
		src/ft_strtrim.c \
		src/ft_substr.c \
		src/ft_tolower.c \
		src/ft_toupper.c \
		src/ft_lstnew_bonus.c \
		src/ft_lstadd_front_bonus.c \
		src/ft_lstsize_bonus.c \
		src/ft_lstlast_bonus.c \
		src/ft_lstadd_back_bonus.c \
		src/ft_lstdelone_bonus.c \
		src/ft_lstclear_bonus.c \
		src/ft_lstiter_bonus.c \
		src/ft_lstmap_bonus.c \
		ft_printf/ft_printf.c \
		ft_printf/ft_printf_utils1.c \
		ft_printf/ft_printf_utils2.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

#Builds the library
all: $(NAME)

$(NAME): $(OBJS)
	 $(AR) $(NAME) $(OBJS)

#RULES

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all 

.PHONY: all clean fclean re bonus