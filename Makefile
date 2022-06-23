# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/19 14:53:15 by yboudoui          #+#    #+#              #
#    Updated: 2022/06/23 07:15:34 by yboudoui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC					=	gcc

CFLAGS				=	-g3 #-Wall -Wextra -Werror -g3

RM					=	rm -f

SRC					=	main.c\
						mlx_wrapper.c\
						vec2/vec2.c\
						pixel.c\
						line.c

OBJ					=	$(SRC:.c=.o)

NAME				=	gg

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ)
	$(MAKE) all -C mlx_linux
	$(CC) $(OBJ) -L mlx_linux -lmlx_Linux -lXext -lX11 -lm -o $(NAME)

all:	$(NAME)

clean:
				$(MAKE) clean -C mlx_linux
				$(RM) $(OBJ)

fclean:		clean
				$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
