/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:17:12 by yboudoui          #+#    #+#             */
/*   Updated: 2022/11/16 08:16:05 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_mlx.h"

void	delete_image(t_image *img)
{
	mlx_destroy_image(img->mlx, img->data);
	free(img);
}

t_image	*image_new(t_mlx *data, int width, int height)
{
	t_image	*out;

	out = ft_calloc(1, sizeof(t_image));
	if (NULL == out)
		return (NULL);
	out->mlx = data->mlx;
	out->height = height;
	out->width = width;
	out->data = mlx_new_image(out->mlx, width, height);
	out->addr = mlx_get_data_addr(out->data,
			&out->bits_per_pixel,
			&out->line_length,
			&out->endian);
	return (out);
}

void	image_clear(t_image *img)
{
	size_t	size;

	size = (img->width - 1) * (img->bits_per_pixel / 8);
	size += (img->height - 1) * (img->line_length);
	ft_memset(img->addr, 0, size);
}

void	image_put_pixel(t_image *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x > data->width)
		return ;
	if (y < 0 || y > data->height)
		return ;
	dst = data->addr;
	x *= (data->bits_per_pixel / 8);
	y *= (data->line_length);
	dst += (y + x);
	*(unsigned int *)dst = color;
}

void	image_put_horizontal_line(t_image *data, int x1, int x2, int y, int color)
{
	char	*dst;
	size_t	size;

	if (y < 0 || y > data->height)
		return ;
	x1 *= (x1 >= 0);
	x2 *= (x2 >= 0);
	if (x1 > data->width)
		x1 = data->width;
	if (x2 > data->width)
		x2 = data->width;
	if (x1 == x2)
		return ;
	size = (abs(x1 - x2)) * (data->bits_per_pixel / 8);
	dst = data->addr;
	x1 *= (data->bits_per_pixel / 8);
	y *= (data->line_length);
	dst += (y + x1);
	ft_memset(dst, color, size);
}
