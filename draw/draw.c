/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:21:13 by yboudoui          #+#    #+#             */
/*   Updated: 2022/11/20 20:46:35 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_vec2	transforme(t_map *map, int pad, t_vec2 center, t_vec2 idx)
{
	t_vec2	out;

	out = center_screen(center);
	out = transforme_vec2(center_map(map, pad, idx));
	out.x += center.x;
	out.y += center.y;
	out.y -= (map->map[idx.y]->array[idx.x] * pad);
	return (out);
}

void	transforme_quad(t_quad *quad, t_map *map, int pad, t_vec2 center, t_vec2 idx)
{
	if (NULL == quad)
		return ;
	quad->point[0][0] = quad->point[1][0];
	quad->point[0][1] = quad->point[1][1];
	quad->point[1][0].coord = transforme(map, pad, center, idx);
	quad->point[1][1].coord = transforme(map, pad, center, (t_vec2){idx.x + 1, idx.y});
}

#define DARK_PINK 0xC52184
#define LIGHT_PINK 0xF9B4ED

static void	interpolate_height(t_quad *quad, t_map *map, t_vec2 idx)
{
	const t_color	dark_pink = {.raw = DARK_PINK};
	const t_color	light_pink = {.raw = LIGHT_PINK};
	float			height;

	if (0 == map->height)
		return ;
	height = map->map[idx.y]->array[idx.x] - map->min_height;
	height /= map->height;
	quad->point[1][0].color = interpolate_color(dark_pink, height, light_pink);
	height = map->map[idx.y]->array[idx.x + 1] - map->min_height;;
	height /= map->height;
	quad->point[1][1].color = interpolate_color(dark_pink, height, light_pink);
}

static void	draw(int pad, t_vec2 center, t_map *map, t_image *img)
{
	t_quad	quad;
	t_vec2	idx;

	quad = (t_quad){0};
	quad.point[1][0].color.raw = DARK_PINK;
	quad.point[1][1].color.raw = DARK_PINK;
	idx = (t_vec2){0};
	while (idx.x < (int)map->max_col - 1)
	{
		idx.y = 0;
		transforme_quad(&quad, map, pad, center, idx);
		while (idx.y < (int)map->max_row)
		{
			transforme_quad(&quad, map, pad, center, idx);
			interpolate_height(&quad, map, idx);
			image_put_quad(img, quad);
			image_put_empty_quad(img, quad);
			idx.y += 1;
		}
		idx.x += 1;
	}
}

static double	get_pad(t_image *img, t_map *map)
{
	double	hypothenuse;
	double	min;

	hypothenuse = sqrt(pow(map->max_col, 2) + pow(map->max_row, 2));
	min = img->height;
	if (img->width < img->height)
		min = img->width;
	min -= 20;
	return (min / hypothenuse);
}

void	draw_image(t_data *data)
{
	double	pad;

//	pad = get_pad(data->mlx->img, data->map);
	pad = get_pad(data->img, data->map);
	pad *= data->pad;
	image_clear(data->img);
	draw(pad, data->center, data->map, data->img);
}
