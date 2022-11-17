/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:37:16 by yboudoui          #+#    #+#             */
/*   Updated: 2022/11/17 18:45:21 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include "memory.h"
# include "vec2.h"
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

t_image	*image_new(t_mlx *data, int width, int height);
void	delete_image(t_image *img);
void	image_clear(t_image *img);

void	image_put_pixel(t_image *data, int x, int y, int color);
void	image_put_horizontal_line(t_image *data, int x[2], int y, int color);

void	draw_line(t_image *img, int color, t_vec2 start, t_vec2 end);

#endif
