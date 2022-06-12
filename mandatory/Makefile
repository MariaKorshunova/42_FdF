# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/14 19:11:05 by jmabel            #+#    #+#              #
#    Updated: 2022/06/11 15:48:50 by jmabel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	../fdf

HEADER		=	fdf.h

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf

SRCS		=	fdf.c				map_read.c			map_error.c\
				map_define_value.c	colors.c			default_value.c\
				array_operations.c	ft_atoi_base10.c	ft_atoi_base16.c\
				matrix_operations.c	matrix_rotate.c \
				image.c		  		line.c				draw.c\
				hook.c\
				../get_next_line/get_next_line.c

LIBFT		=	../libft/libft.a
LIBMLX		=	../libmlx/libmlx.a

OBJ			=	$(SRCS:%.c=%.o)

all			:	$(NAME)

$(NAME)		:	$(OBJ) $(LIBFT) $(LIBMLX)
	$(CC) $(CFLAGS) $(LIBFT) $(LIBMLX) -framework OpenGL -framework AppKit $(OBJ) -o $(NAME)

$(LIBFT)	:
	make -C ../libft

$(LIBMLX)	:
	make -C ../libmlx

%.o			:	%.c $(HEADER)
	$(CC) $(CFLAGS) -c  $<  -o $@

.PHONY		:	all clean fclean re

clean		:
	$(RM) $(OBJ) $(OBJ_CHECKER)
	make clean -C ../libft
	make clean -C ../libmlx

fclean		: clean
	$(RM) $(NAME) $(NAME_CHECKER)
	make fclean -C ../libft

re			:	fclean all