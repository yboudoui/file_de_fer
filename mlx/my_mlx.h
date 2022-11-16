/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:00:50 by yboudoui          #+#    #+#             */
/*   Updated: 2022/11/16 15:17:59 by yboudoui         ###   ########.fr       */
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
	int		width;
	int		height;
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
void	image_clear(t_image *img);
void	image_put_pixel(t_image *data, int x, int y, int color);
void	image_put_horizontal_line(t_image *data, int x1, int x2, int y, int color);
void	draw_line(t_image *img, int color, t_vec2 start, t_vec2 end);

struct	s_data {
	t_mlx	*mlx;
	t_map	*map;
	bool	redraw;
	double	pad;
};

void	delete_data(void *data);
t_data	*create_data(char *path, int width, int height);


#include <limits.h>

typedef struct s_quad {
	t_vec2	point[4];
}	t_quad;

void	draw_quad(t_image *img, t_quad quad);
#endif
