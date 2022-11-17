/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:17:12 by yboudoui          #+#    #+#             */
/*   Updated: 2022/11/17 18:46:14 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"

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
	ft_bzero(img->addr, size);
}

void	image_put_pixel(t_image *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= data->width)
		return ;
	if (y < 0 || y >= data->height)
		return ;
	dst = data->addr;
	x *= (data->bits_per_pixel / 8);
	y *= (data->line_length);
	dst += (y + x);
	*(unsigned int *)dst = color;
}

void	image_put_horizontal_line(t_image *data, int x[2], int y, int color)
{
	char	*dst;
	size_t	size;

	if (y < 0 || y > data->height)
		return ;
	x[0] *= (x[0] >= 0);
	x[1] *= (x[1] >= 0);
	if (x[0] >= data->width)
		x[0] = data->width;
	if (x[1] >= data->width)
		x[1] = data->width;
	if (x[0] == x[1])
		return ;
	x[0] *= (data->bits_per_pixel / 8);
	x[1] *= (data->bits_per_pixel / 8);
	size = abs(x[1] - x[0]);
	dst = data->addr;
	y *= (data->line_length);
	if (x[0] < x[1])
		dst += (y + x[0]);
	else
		dst += (y + x[1]);
	ft_memset(dst, color, size);
}
