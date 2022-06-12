# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/14 19:11:05 by jmabel            #+#    #+#              #
#    Updated: 2022/06/11 15:51:20 by jmabel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	../fdf_bonus

HEADER		=	fdf_bonus.h

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf

SRCS		=	fdf_bonus.c					map_read_bonus.c		map_error_bonus.c\
				map_define_value_bonus.c	colors_bonus.c			default_value_bonus.c\
				array_operations_bonus.c	ft_atoi_base10_bonus.c	ft_atoi_base16_bonus.c\
				matrix_operations_bonus.c	matrix_rotate_bonus.c\
				image_bonus.c		  		line_bonus.c			draw_bonus.c\
				hook_bonus.c\
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