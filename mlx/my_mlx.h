/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:00:50 by yboudoui          #+#    #+#             */
/*   Updated: 2022/11/07 18:49:32 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_MLX_H
# define MY_MLX_H

# include <stdlib.h>
# include "mlx.h"
# include "mlx_int.h"
# include "vec2.h"
# include "memory.h"
# include "parsing.h"

typedef struct s_mlx	t_mlx;
typedef struct s_image	t_image;
typedef struct s_data	t_data;

struct s_mlx {
	void	*mlx;
	void	*win;
	t_image	*img;
};

struct s_image {
	void	*mlx;
	void	*data;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
};

t_mlx	*create_mlx(char *title, int width, int height);
void	delete_mlx(void *data);

void	delete_image(t_image *img);
t_image	*image_new(t_mlx *data, int width, int height);
void	image_put_pixel(t_image *data, int x, int y, int color);


struct	s_data {
	t_mlx	*mlx;
	t_map	*map;
};

void	delete_data(void *data);
t_data	*create_data(char *path, int width, int height);

typedef struct s_line {
	t_vec2	start;
	t_vec2	end;
}	t_line;
t_line	ft_line(t_vec2 start, t_vec2 end);
void	draw_line(t_line line, t_image *img);

#endif
