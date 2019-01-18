# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmorgan- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/07 14:39:13 by pmorgan-          #+#    #+#              #
#    Updated: 2019/01/14 16:03:22 by pmorgan-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, $(NAME), clean, fclean, re

NAME = fillit

SRCS =	./*.c	
LSRCS =	./libft/*.c
OBJS =	$(SRCS:.c=.o)
LOBJS =	$(LSRCS:.c=.o)
INCS =	-I ./ -I ./libft/ 
FLAGS =	-g -Wall -Werror -Wextra 
LIB =	-L./libft -lft

all: $(NAME)

$(NAME): $(SRCS)
	make -C ./libft/
	gcc $(FLAGS) -c $? $(INCS)
	gcc -o $(NAME) $(LIB) $(OBJS) $(LOBJS)

clean:	libclean
	@/bin/rm -f $(OBJS)	

fclean:	clean libfclean
	@/bin/rm -f $(NAME)

libclean:
	@make clean -C ./libft/

libfclean:
	@make fclean -C ./libft/

libre:
	@make re -C ./libft/

re: fclean all
