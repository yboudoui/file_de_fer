/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:21:13 by yboudoui          #+#    #+#             */
/*   Updated: 2022/11/25 12:17:40 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define NO_BONUS 1

static t_vec2	transforme(t_data *data, t_vec2 idx)
{
	t_vec2	out;

	out = center_screen(data->center);
	out = transforme_vec2(center_map(data->map, data->pad, idx));
	out.x += data->center.x;
	out.y += data->center.y;
	out.y -= (map_get_height(data->map, idx) * data->height * data->pad);
	return (out);
}

static void	transforme_quad(t_quad *quad, t_data *data, t_vec2 idx)
{
	if (NULL == quad)
		return ;
	quad->point[0][0] = quad->point[1][0];
	quad->point[0][1] = quad->point[1][1];
	quad->point[1][0].color.raw = map_get_color(data->map, idx);
	quad->point[1][0].coord = transforme(data, idx);
	idx = (t_vec2){idx.x + 1, idx.y};
	quad->point[1][1].color.raw = map_get_color(data->map, idx);
	quad->point[1][1].coord = transforme(data, idx);
}

static inline void	drawer(t_data *data, t_quad quad)
{
/*
	if (NO_BONUS)
		return ((void)image_put_empty_quad(data->img, quad));
*/
	image_put_quad(data->img, quad);
//	image_put_empty_quad(data->img, quad);
//	image_put_pixel(data->img, quad.point[0][0]);
}

void	draw_image(t_data *data)
{
	t_quad	quad;
	t_vec2	idx;

	idx = (t_vec2){0};
	quad = (t_quad){0};
	quad.point[1][0].color = data->map->palette[0];
	quad.point[1][1].color = data->map->palette[0];
	image_clear(data->img, data->map->palette[2]);
	transforme_quad(&quad, data, idx);
	while (idx.x < data->map->size.x - 1)
	{
		if (idx.y == data->map->size.y)
		{
			idx.x += 1;
			idx.y = 0;
			transforme_quad(&quad, data, idx);
		}
		else
		{
			transforme_quad(&quad, data, idx);
			drawer(data, quad);
			idx.y += 1;
		}
	}
}
