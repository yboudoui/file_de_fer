/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:17:12 by yboudoui          #+#    #+#             */
/*   Updated: 2022/11/20 20:30:49 by yboudoui         ###   ########.fr       */
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

//0x334139
//0x1E2D24
void	image_clear(t_image *img)
{
	size_t	size;

	size = (img->width - 1) * (img->bits_per_pixel / 8);
	size += (img->height - 1) * (img->line_length);
	ft_memset(img->addr, 0x1E2D24, size);
//	ft_bzero(img->addr, size);
}

inline void	image_put_horizontal_line(t_image *data, int x[2], int y, int color)
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

unsigned int	get_color(t_image *img, t_vec2 pos)
{
	char	*dst;

	dst = img->addr;
	pos.x *= (img->bits_per_pixel / 8);
	pos.y *= (img->line_length);
	dst += (pos.y + pos.x);
	return (*(unsigned int *)dst);
}

inline static t_color	average_color(t_image *img, t_vec2 index, t_vec2 ratio)
{
	t_vec2	idx;
	t_color	tmp;
	float	average;
	float	chanel[4];

	average = (ratio.x * ratio.y);
	ratio = add_vec2(ratio, index);
	ft_memset(chanel, 0, sizeof(int) * 4);
	idx = index;
	while (idx.x < ratio.x)
	{
		idx.y = index.y;
		while (idx.y < ratio.y)
		{
			tmp.raw = get_color(img, idx);
			chanel[0] += tmp.chanel[0];
			chanel[1] += tmp.chanel[1];
			chanel[2] += tmp.chanel[2];
			chanel[3] += tmp.chanel[3];
			idx.y++;
		}
		idx.x++;
	}
	return ((t_color){
		.chanel = {
		[0] = chanel[0] / average,
		[1] = chanel[1] / average,
		[2] = chanel[2] / average,
		[3] = chanel[3] / average,
		},
	});
}

void	down_sample(t_image *in, t_image *out)
{
	t_vec2	idx;
	t_vec2	ratio;
	t_pixel	pix;

	ratio.x = in->width / out->width;
	ratio.y = in->height / out->height;
	idx = (t_vec2){0};
	while (idx.x < out->width)
	{
		idx.y = 0;
		while (idx.y < out->height)
		{
			pix.coord = idx;
			pix.color = average_color(in, idx, ratio);
			image_put_pixel(out, pix);
			idx.y++;
		}
		idx.x++;
	}
}

static inline bool	coord_out_of_image(t_image *img, t_vec2 coord)
{
	if (coord.x < 0 || coord.x >= img->width)
		return (true);
	if (coord.y < 0 || coord.y >= img->height)
		return (true);
	return (false);
}

inline void	image_put_pixel(t_image *img, t_pixel pixel)
{
	char	*dst;

	if (coord_out_of_image(img, pixel.coord))
		return ;
	dst = img->addr;
	pixel.coord.x *= (img->bits_per_pixel / 8);
	pixel.coord.y *= (img->line_length);
	dst += (pixel.coord.y + pixel.coord.x);
	*(unsigned int *)dst = pixel.color.raw;
}
