# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/14 19:11:05 by jmabel            #+#    #+#              #
#    Updated: 2022/05/10 15:33:52 by jmabel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cube

HEADER		=	cube.h

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf

SRCS		=	main.c	transform.c 	draw.c\
				matrix_operations.c

LIBFT		=	../libft/libft.a
LMLX		=	/usr/local/lib/ -lmlx -framework OpenGL -framework Appkit

OBJ			=	$(SRCS:%.c=%.o)

all			:	$(NAME)

$(NAME)		:	$(OBJ) $(LIBFT)
	$(CC) $(OBJ) -L ../libft -lft -L $(LMLX) -o $(NAME)

$(LIBFT)	:
	make -C ../libft

%.o			:	%.c $(HEADER)
	$(CC) $(CFLAGS) -c  $<  -o $@

.PHONY		:	all clean fclean re

clean		:
	$(RM) $(OBJ) $(OBJ_CHECKER)
	make clean -C ./libft

fclean		: clean
	$(RM) $(NAME) $(NAME_CHECKER)
	make fclean -C ../libft

re			:	fclean all