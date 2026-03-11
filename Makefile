# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/11 16:03:18 by mvelasqu          #+#    #+#              #
#    Updated: 2026/03/11 13:32:57 by mvelasqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Description

NAME		= pipex
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

LIBDIR		= libft
LIBFLAGS	= $(LIBDIR)/libft.a

INCDIR		= includes
INCFLAGS	= -I$(INCDIR) -I$(LIBDIR)/includes

SRCS		= main.c \
				src/helper.c \
				src/initialize.c \
				src/path.c \
				src/child.c
OBJS		= $(SRCS:.c=.o)

#Commands
all: $(NAME)

$(NAME): $(LIBFLAGS) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFLAGS) -o $(NAME)

$(LIBFLAGS):
	$(MAKE) -C $(LIBDIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBDIR) clean

fclean:
	$(RM) $(NAME) $(OBJS)
	$(MAKE) -C $(LIBDIR) fclean

re:
	$(MAKE) fclean all

phony: all fclean clean re