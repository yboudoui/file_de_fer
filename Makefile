# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/19 14:53:15 by yboudoui          #+#    #+#              #
#    Updated: 2022/11/17 18:41:07 by yboudoui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	fdf

CC					=	cc

CFLAGS				=	-Wall -Wextra -Werror

RM					=	rm -f

# **************************************************************************** #

SRCS	=\
./mlx/mlx_utils/vec2/vec2.c\
./mlx/mlx_utils/line/line.c\
./mlx/mlx_utils/quad/quad.c\
./mlx/mlx_utils/quad/empty_quad.c\
./mlx/mlx_utils/mlx_utils.c\
./mlx/mlx_utils/image/image.c\
./main.c\
./parsing/utils/str/ft_strtrim.c\
./parsing/utils/str/ft_strlen.c\
./parsing/utils/str/ft_substr.c\
./parsing/utils/str/ft_split.c\
./parsing/utils/lst/source/ft_lst_remove_one.c\
./parsing/utils/lst/source/ft_lstclear.c\
./parsing/utils/lst/source/transform.c\
./parsing/utils/lst/source/ft_lstmap.c\
./parsing/utils/lst/source/add.c\
./parsing/utils/lst/source/ft_lstlast.c\
./parsing/utils/is_charset/is_charset.c\
./parsing/utils/atoi_to.c\
./parsing/utils/file/file.c\
./parsing/utils/memory/ft_memcpy.c\
./parsing/utils/memory/ft_calloc.c\
./parsing/utils/memory/ft_memset.c\
./parsing/utils/int_array/int_array.c\
./parsing/utils/get_next_line/get_next_line_utils.c\
./parsing/utils/get_next_line/get_next_line.c\
./parsing/data/data.c\
./parsing/map/map.c\
./parsing/atoi_words.c\
./parsing/parsing.c\
./draw/draw.c\
./draw/transform.c\

INCS	=\
./mlx/mlx_linux\
./mlx/mlx_utils/image\
./mlx/mlx_utils/vec2\
./mlx/mlx_utils/line\
./mlx/mlx_utils/quad\
./mlx/mlx_utils\
./parsing/utils/str\
./parsing/utils/lst/include\
./parsing/utils/is_charset\
./parsing/utils\
./parsing/utils/file\
./parsing/utils/memory\
./parsing/utils/int_array\
./parsing/utils/get_next_line\
./parsing/data\
./parsing\
./parsing/map\
./draw\

# **************************************************************************** #

OBJS				=	$(SRCS:.c=.o)

.c.o:
	$(CC) $(CFLAGS)	\
		$(addprefix -I , $(INCS))	\
		-c $<	\
		-o $(<:.c=.o)	
	@echo $<

$(NAME):	$(OBJS)
			$(MAKE) all -C mlx/mlx_linux
			$(CC) $(OBJS) -L mlx/mlx_linux -lmlx_Linux -lmlx -lXext -lX11 -lm -o $(NAME)

all:		$(NAME)

clean:
			$(MAKE) clean -C mlx/mlx_linux
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

valgrind:	all
			valgrind -q --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) ./asset/42.fdf

.PHONY:		all clean fclean re
