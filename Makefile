# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/14 19:11:05 by jmabel            #+#    #+#              #
#    Updated: 2022/03/21 16:16:32 by jmabel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fdf

HEADER		=	fdf.h

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf

SRCS		=	fdf.c	read_map.c	maps_error.c\
				put_image.c\
				array_operations.c\
				./get_next_line/get_next_line.c

LIBFT		=	./libft/libft.a
LMLX		=	/usr/local/lib/ -lmlx -framework OpenGL -framework Appkit

OBJ			=	$(SRCS:%.c=%.o)

all			:	$(NAME)

$(NAME)		:	$(OBJ) $(LIBFT)
	$(CC) $(OBJ) -L ./libft -lft -L $(LMLX) -o $(NAME)

$(LIBFT)	:
	make -C ./libft

%.o			:	%.c $(HEADER)
	$(CC) $(CFLAGS) -c  $<  -o $@

.PHONY		:	all clean fclean re

clean		:
	$(RM) $(OBJ) $(OBJ_CHECKER)
	make clean -C ./libft

fclean		: clean
	$(RM) $(NAME) $(NAME_CHECKER)
	make fclean -C ./libft

re			:	fclean all