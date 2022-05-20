# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/20 19:54:01 by jmabel            #+#    #+#              #
#    Updated: 2022/05/20 19:54:26 by jmabel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all		:
	make -C ./mandatory

bonus	:
	make -C ./bonus

.PHONY	:	all clean fclean re bonus

clean	:
	make clean -C ./mandatory
	make clean -C ./bonus

fclean	: clean
	make fclean -C ./mandatory
	make fclean -C ./bonus

re		: fclean all
rebonus : fclean bonus