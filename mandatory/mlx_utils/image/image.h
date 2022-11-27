/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:37:16 by yboudoui          #+#    #+#             */
/*   Updated: 2022/11/27 06:15:58 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include "line.h"
# include "mlx_utils.h"

typedef struct s_mlx	t_mlx;

typedef struct s_image {
	void	*mlx;
	int		width;
	int		height;
	void	*data;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_triangle {
	t_pixel	point[3];
}	t_triangle;

typedef struct s_quad {
	t_pixel	point[2][2];
}	t_quad;

void	down_sample(t_image *in, t_image *out);

t_image	*image_new(t_mlx *data, int width, int height);
void	delete_image(t_image *img);
void	image_clear(t_image *img, t_color color);

void	image_put_pixel(t_image *img, t_pixel pixel);
void	image_put_line(t_image *img, t_pixel start, t_pixel end);

void	image_put_triangle(t_image *img, t_pixel points[3]);

void	image_put_quad(t_image *img, t_quad quad);
void	image_put_empty_quad(t_image *img, t_quad quad);
#endif
