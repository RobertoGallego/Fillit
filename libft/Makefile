# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmorgan- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/12 14:13:21 by pmorgan-          #+#    #+#              #
#    Updated: 2018/12/01 17:04:17 by pmorgan-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

CC =	gcc
CFLAGS = -Wall -Werror -Wextra
INCDIR = ./
CMPDIR = ./
SRCS =	*.c
OBJS =	$(SRCS:.c=.o)

$(NAME): $(INCDIR)/libft.h
	$(CC) $(CFLAGS) -c $(SRCS) -I$(INCDIR)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

all: $(NAME)

clean:
	@/bin/rm -f $(OBJS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all 
