# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/19 14:53:15 by yboudoui          #+#    #+#              #
#    Updated: 2022/10/02 11:59:27 by yboudoui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	fdf

CC					=	cc

CFLAGS				=	-Wall -Wextra -Werror -g3

RM					=	rm -f

# **************************************************************************** #

VEC2_DIR			=	vec2/

VEC2_SRC			=	$(addprefix $(VEC2_DIR),			\
						vec2.c								\
						)

VEC2_INC			=	$(addprefix $(VEC2_DIR),			\
						.									\
						)

# **************************************************************************** #

LINE_DIR			=	line/

LINE_SRC			=	$(addprefix $(LINE_DIR),			\
						line.c								\
						)

LINE_INC			=	$(addprefix $(LINE_DIR),			\
						.									\
						)

# **************************************************************************** #

WINDOW_DIR			=	window/

WINDOW_SRC			=	$(addprefix $(WINDOW_DIR),			\
						window.c							\
						)

WINDOW_INC			=	$(addprefix $(WINDOW_DIR),			\
						.									\
						)

# **************************************************************************** #

MLX_WRAPPER_DIR		=	mlx_wrapper/

MLX_WRAPPER_SRC		=	$(addprefix $(MLX_WRAPPER_DIR),		\
						$(VEC2_SRC)							\
						$(LINE_SRC)							\
						$(WINDOW_SRC)						\
						mlx_wrapper.c						\
						mlx_obj.c							\
						)

MLX_WRAPPER_INC		=	$(addprefix $(MLX_WRAPPER_DIR),		\
						$(VEC2_INC)							\
						$(LINE_INC)							\
						$(WINDOW_INC)						\
						.									\
						)

# **************************************************************************** #

SRCS				=	$(MLX_WRAPPER_SRC)			\
						main.c						\

INCS				=	$(MLX_WRAPPER_INC)			\
						.							\

OBJS				=	$(SRCS:.c=.o)

.c.o:
	@$(CC) $(CFLAGS)	\
		$(addprefix -I , $(INCS))	\
		-c $<	\
		-o $(<:.c=.o)	
	@echo $<

$(NAME):	$(OBJS)
			$(MAKE) all -C mlx_wrapper/mlx_linux
			$(CC) $(OBJS) -L mlx_wrapper/mlx_linux -lmlx_Linux -lXext -lX11 -lm -o $(NAME)

all:		$(NAME)

clean:
			$(MAKE) clean -C mlx_wrapper/mlx_linux
			$(RM) $(OBJS)

re:			fclean all

valgrind:	all
			valgrind --leak-check=full --show-leak-kinds=all -s ./$(NAME)

.PHONY:		all clean fclean re
