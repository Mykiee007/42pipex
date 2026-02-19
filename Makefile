# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/11 16:03:18 by mvelasqu          #+#    #+#              #
#    Updated: 2026/02/19 10:14:06 by mvelasqu         ###   ########.fr        #
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
INCFLAGS	= $(LIBDIR)/includes

SRCS		= main.c src_pipex/pipex_utls_1.c
OBJS		= $(SRCS:.c=.o)

#Commands

$(NAME): $(LIBFLAGS) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFLAGS) -o $(NAME)

$(LIBFLAGS):
	$(MAKE) -C $(LIBDIR)

%.o: %.c 
	$(CC) $(CFLAGS) -I$(INCFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBDIR) clean

fclean: clean
	$(RM) $(NAME) 
	$(MAKE) -C $(LIBDIR) fclean

re:
	fclean all

phony: all fclean clean re