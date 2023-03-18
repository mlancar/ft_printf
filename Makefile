# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malancar <malancar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/28 12:34:59 by malancar          #+#    #+#              #
#    Updated: 2023/03/18 06:18:16 by malancar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= gcc

RM	= rm -f

NAME	= libftprintf.a

CFLAGS	= -Wextra -Wall -Werror

SRC =	ft_printf.c	\
		check.c		\
		format.c	


OBJ =	$(SRC:.c=.o)

HEADER =	libftprintf.h

all:	$(NAME)

$(NAME):	$(OBJ) $(HEADER)
	ar -rcs $(NAME) $(OBJ)

%.o:	%.c
	@$(CC) $(FLAGS) -o $@ -c $^

clean:
	@$(RM) $(OBJ)

fclean:	clean
	@$(RM) $(NAME)

re:	fclean all

.PHONY: all fclean clean re
