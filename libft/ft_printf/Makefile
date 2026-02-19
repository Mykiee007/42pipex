# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/03 10:40:00 by mvelasqu          #+#    #+#              #
#    Updated: 2025/12/18 13:08:40 by mvelasqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Varibales
NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar
AFLAGS = rcs

#Files
SRCS = ft_printf_utils1.c ft_printf_utils1.c ft_printf.c
OBJS = $(SRCS:.c=.o)

#Commands
all: $(NAME)

$(NAME): $(OBJS)  
	$(AR) $(AFLAGS) $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re