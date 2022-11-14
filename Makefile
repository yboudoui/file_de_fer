# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/19 14:53:15 by yboudoui          #+#    #+#              #
#    Updated: 2022/11/14 18:37:22 by yboudoui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	fdf

CC					=	cc

CFLAGS				=	-Wall -Wextra -Werror -g3

RM					=	rm -f

# **************************************************************************** #

SRCS	=\
./mlx/data.c\
./mlx/my_mlx.c\
./mlx/image.c\
./mlx/line.c\
./main.c\
./vec2/vec2.c\
./parsing/utils/is_charset/is_charset.c\
./parsing/utils/atoi_to.c\
./parsing/utils/int_array/int_array.c\
./parsing/utils/get_next_line/get_next_line_utils.c\
./parsing/utils/get_next_line/get_next_line.c\
./parsing/str/ft_strtrim.c\
./parsing/str/ft_strlen.c\
./parsing/str/ft_substr.c\
./parsing/str/ft_split.c\
./parsing/lst/source/ft_lst_remove_one.c\
./parsing/lst/source/ft_lstclear.c\
./parsing/lst/source/transform.c\
./parsing/lst/source/ft_lstmap.c\
./parsing/lst/source/add.c\
./parsing/lst/source/ft_lstlast.c\
./parsing/atoi_words.c\
./parsing/file/file.c\
./parsing/memory/ft_memcpy.c\
./parsing/memory/ft_calloc.c\
./parsing/parsing.c\
./draw.c\
./transform.c\

INCS	=\
./\
./mlx\
./mlx/mlx_linux\
./vec2\
./parsing/utils/is_charset\
./parsing/utils\
./parsing/utils/int_array\
./parsing/utils/get_next_line\
./parsing/str\
./parsing/lst/include\
./parsing\
./parsing/file\
./parsing/memory\

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
