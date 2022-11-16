/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:21:13 by yboudoui          #+#    #+#             */
/*   Updated: 2022/11/16 15:36:21 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
static void	draw_row(int pad, t_map *map, t_image *img)
{
	t_vec2	start;
	t_vec2	end;
	t_vec2	idx;

	idx = (t_vec2){0};
	while (idx.y < (int)map->max_row)
	{
		idx.x = 0;
		end = center_screen(transforme_vec2(center_map(map, pad, idx)));
		while (idx.x < (int)map->max_col)
		{
			start = end;
			end = center_screen(transforme_vec2(center_map(map, pad, idx)));
			end.y -= (map->map[idx.y]->array[idx.x] * pad);
			draw_line(img, start, end);
			idx.x += 1;
		}
		idx.y += 1;
	}
}

static void	draw_col(int pad, t_map *map, t_image *img)
{
	t_vec2	start;
	t_vec2	end;
	t_vec2	idx;

	idx = (t_vec2){0};
	while (idx.x < (int)map->max_col)
	{
		idx.y = 0;
		end = center_screen(transforme_vec2(center_map(map, pad, idx)));
		while (idx.y < (int)map->max_row)
		{
			start = end;
			end = center_screen(transforme_vec2(center_map(map, pad, idx)));
			end.y -= (map->map[idx.y]->array[idx.x] * pad);
			draw_line(img, start, end);
			idx.y += 1;
		}
		idx.x += 1;
	}
}
*/

static void	draw(int pad, t_map *map, t_image *img)
{
	t_vec2	start[2];
	t_vec2	end[2];
	t_vec2	idx;

	idx = (t_vec2){0};
	while (idx.x < (int)map->max_col - 1)
	{
		idx.y = 0;
		end[0] = center_screen(transforme_vec2(center_map(map, pad, idx)));
		end[1] = center_screen(transforme_vec2(center_map(map, pad, (t_vec2){idx.x + 1, idx.y})));
		while (idx.y < (int)map->max_row)
		{
			start[0] = end[0];
			start[1] = end[1];
			end[0] = center_screen(transforme_vec2(center_map(map, pad, idx)));
			end[1] = center_screen(transforme_vec2(center_map(map, pad, (t_vec2){idx.x + 1, idx.y})));
			end[0].y -= (map->map[idx.y]->array[idx.x] * pad);
			end[1].y -= (map->map[idx.y]->array[idx.x+1] * pad);


			draw_quad(img, (t_quad){{
					start[0], end[0], start[1], end[1],
				}});
			idx.y += 1;
		}
		idx.x += 1;
	}
}

static double	get_pad(t_map *map)
{
	double	hypothenuse;
	double	min;

	hypothenuse = sqrt(pow(map->max_col, 2) + pow(map->max_row, 2));
	min = HEIGHT;
	if (WIDTH < HEIGHT)
		min = WIDTH;
	min -= 20;
	return (min / hypothenuse);
}

void	draw_image(t_data *data)
{
	double	pad;

	pad = get_pad(data->map);
	pad *= data->pad;
	draw(pad, data->map, data->mlx->img);
/*
	draw_row(pad, data->map, data->mlx->img);
	draw_col(pad, data->map, data->mlx->img);
*/
}
