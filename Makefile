# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/19 14:53:15 by yboudoui          #+#    #+#              #
#    Updated: 2023/09/16 10:50:38 by yboudoui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	fdf

CC					=	clang

EXTRA_FLAG			=	-Ofast -flto=full -DBONUS

CFLAGS				=	-Wall -Wextra -Werror

RM					=	rm -f

MLX_DIR				=	mlx_linux

LINK				=	-L $(MLX_DIR) -lmlx_Linux -lmlx -lXext -lX11 -lm


# **************************************************************************** #

SRCS				= $(addprefix srcs/, 									\
mlx_utils/color/color.c														\
mlx_utils/vec2/vec2.c														\
mlx_utils/event/window/window.c												\
mlx_utils/event/event.c														\
mlx_utils/event/keyboard/keyboard.c											\
mlx_utils/event/mouse/mouse.c												\
mlx_utils/line/line.c														\
mlx_utils/mlx_utils.c														\
mlx_utils/image/quad.c														\
mlx_utils/image/triangle.c													\
mlx_utils/image/image.c														\
mlx_utils/image/line.c														\
utils/str/ft_strtrim.c														\
utils/str/ft_strncmp.c														\
utils/str/ft_strlen.c														\
utils/str/ft_substr.c														\
utils/str/ft_split.c														\
utils/lst/source/ft_lst_remove_one.c										\
utils/lst/source/ft_lstclear.c												\
utils/lst/source/ft_lstmap.c												\
utils/lst/source/add.c														\
utils/lst/source/create.c													\
utils/lst/source/ft_lstlast.c												\
utils/is_charset/is_charset.c												\
utils/atoi_to.c																\
utils/file/file.c															\
utils/memory/ft_memcpy.c													\
utils/memory/ft_calloc.c													\
utils/memory/ft_memset.c													\
utils/int_array/int_array.c													\
utils/get_next_line/get_next_line_utils.c									\
utils/get_next_line/get_next_line.c											\
main.c																		\
data/data.c																	\
parsing/atoi_words.c														\
parsing/parsing.c															\
map/map.c																	\
map/getter.c																\
draw/event_state.c															\
draw/draw.c																	\
draw/transform.c															\
)

INCS				= $(addprefix srcs/,									\
mlx_utils/color																\
mlx_utils/vec2																\
mlx_utils/event																\
mlx_utils/event/window														\
mlx_utils/event/keyboard													\
mlx_utils/event/mouse														\
mlx_utils/line																\
mlx_utils																	\
mlx_utils/image																\
utils/str																	\
utils/lst/include															\
utils/is_charset															\
utils																		\
utils/file																	\
utils/memory																\
utils/int_array																\
utils/get_next_line															\
data																		\
parsing																		\
map																			\
draw																		\
)\
$(MLX_DIR)																	\

# **************************************************************************** #

OBJS				=	$(SRCS:.c=.o)

all:		$(NAME)

$(OBJS):	%.o : %.c
			@echo $(CC) $(CFLAGS) $@
			@$(CC) $(CFLAGS) $(addprefix -I , $(INCS)) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			@$(MAKE) -si all -C $(MLX_DIR)
			@echo $(CC) $(CFLAGS) $(NAME)
			@$(CC) $(CFLAGS) $(OBJS) $(LINK) -o $(NAME)

bonus:		CFLAGS += $(EXTRA_FLAG)
bonus:		re

clean:
			@$(RM) $(OBJS)

fclean:		clean
			@$(MAKE) -si clean -C $(MLX_DIR)
			@$(RM) $(NAME)

re:			fclean all

valgrind:	fclean
			@$(MAKE) all -C . EXTRA_FLAG="-g3"
			@valgrind														\
			-s																\
			--leak-check=full												\
			--show-leak-kinds=all											\
			--track-origins=yes												\
			./$(NAME) ./asset/42.fdf										\

.PHONY:		all clean fclean re bonus
