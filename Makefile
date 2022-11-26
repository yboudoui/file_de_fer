# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/19 14:53:15 by yboudoui          #+#    #+#              #
#    Updated: 2022/11/26 14:27:00 by yboudoui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	fdf

CC					=	cc

EXTRA_FLAG			=

CFLAGS				=	-Wall -Wextra -Werror $(EXTRA_FLAG)

RM					=	rm -f

# **************************************************************************** #

SRCS	=\
./mlx/mlx_utils/color/color.c\
./mlx/mlx_utils/vec2/vec2.c\
./mlx/mlx_utils/line/line.c\
./mlx/mlx_utils/mlx_utils.c\
./mlx/mlx_utils/event.c\
./mlx/mlx_utils/image/quad.c\
./mlx/mlx_utils/image/triangle.c\
./mlx/mlx_utils/image/image.c\
./mlx/mlx_utils/image/line.c\
./main.c\
./parsing/utils/str/ft_strtrim.c\
./parsing/utils/str/ft_strlen.c\
./parsing/utils/str/ft_substr.c\
./parsing/utils/str/ft_split.c\
./parsing/utils/lst/source/ft_lst_remove_one.c\
./parsing/utils/lst/source/ft_lstclear.c\
./parsing/utils/lst/source/ft_lstmap.c\
./parsing/utils/lst/source/add.c\
./parsing/utils/lst/source/create.c\
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
./parsing/map/getter.c\
./parsing/atoi_words.c\
./parsing/parsing.c\
./draw/draw.c\
./draw/event_state.c\
./draw/transform.c\

INCS	=\
./mlx/mlx_linux\
./mlx/mlx_utils/color\
./mlx/mlx_utils/vec2\
./mlx/mlx_utils/line\
./mlx/mlx_utils\
./mlx/mlx_utils/image\
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
	@$(CC) $(CFLAGS)	\
		$(addprefix -I , $(INCS))	\
		-c $<	\
		-o $(<:.c=.o)	
	@echo $(CC) $(CFLAGS) $<

$(NAME):	$(OBJS)
			@$(MAKE) -si all -C mlx/mlx_linux
			@$(CC) $(CFLAGS) $(OBJS) -L mlx/mlx_linux -lmlx_Linux -lmlx -lXext -lX11 -lm -o $(NAME)

all:		$(NAME)

clean:
			@$(MAKE) -si clean -C mlx/mlx_linux
			@$(RM) $(OBJS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

bonus:		fclean
			@$(MAKE) -si all -C mlx/mlx_linux
			@$(MAKE) all -C . EXTRA_FLAG="-Ofast -flto=full -DBONUS"

valgrind:	fclean
			@$(MAKE) all -C . EXTRA_FLAG="-g3"
			valgrind -q --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) ./asset/42.fdf

.PHONY:		all clean fclean re
