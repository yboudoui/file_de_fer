/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:17:12 by yboudoui          #+#    #+#             */
/*   Updated: 2022/11/15 18:21:45 by yboudoui         ###   ########.fr       */
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
