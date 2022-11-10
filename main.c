/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 14:51:33 by yboudoui          #+#    #+#             */
/*   Updated: 2022/11/10 17:02:16 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//http://www.cs.yale.edu/homes/aspnes/classes/223/notes.html
#include "my_mlx.h"
#include "parsing.h"

#define WIDTH 1900
#define HEIGHT 800

#include <stdio.h>

t_vec2	vec2_int(int in)
{
	return ((t_vec2){
		.x = in,
		.y = in
	});
}

t_vec2	vec2_mul(t_vec2 a, t_vec2 b)
{
	return ((t_vec2){
		.x = (a.x * b.x),
		.y = (a.x * b.x)
	});
}

t_vec2	vec2_add(t_vec2 a, t_vec2 b)
{
	return ((t_vec2){
		.x = (a.x + b.x),
		.y = (a.x + b.x)
	});
}

t_vec2	transforme_vec2(t_vec2 in)
{
	t_vec2			out;
//	const t_vec2	x = {2, 1};
//	const t_vec2	y = {-2, 1};


	out = (t_vec2){
		.x = (in.x - in.y),
		.y = ((in.x / 2) + (in.y / 2)),
	};
/*
	out = vec2_add(
					vec2_mul(x ,vec2_int(in.x)),
					vec2_mul(y, vec2_int(in.y))
					);
*/
//	return (vec2_add(out, vec2_int(300)));
	out.x += 600;
	return (out);
}

t_line	transforme(t_line line)
{
	t_line	out;

	out.start = transforme_vec2(line.start);
	out.end = transforme_vec2(line.end);
	return (out);
}

void	print_line(t_line in)
{
	printf("start\t%d %d\nend\t%d %d\n", in.start.x, in.start.y, in.end.x, in.end.y);
}
/*
void	draw_col(int pad, t_map *map, t_image *img)
{
	static t_line	line_col = {0};
	size_t			x_idx;
	size_t			y_idx;

	y_idx = 0;
	while (y_idx < map->max_row - 1)
	{
		line_col.start.y += pad;
		line_col.end.y = line_col.start.y + pad;
		x_idx = 0;
		printf("hey\n");
		while (x_idx < map->map[y_idx]->len)
		{
			line_col.start.x += pad;
			line_col.end.x += pad;
			t_line	tmp = transforme(line_col);
			print_line(tmp);
			tmp.start.y -= (map->map[y_idx]->array[x_idx] * 7);
			tmp.end.y -= (map->map[y_idx]->array[x_idx] * 7);
			draw_line(tmp, img);
//			draw_line(line_col, img);
			x_idx += 1;
		}
		line_col.start.x = 0;
		line_col.end.x = 0;
		y_idx += 1;
	}
	line_col = (t_line){0};
}

void	draw_row(int pad, t_map *map, t_image *img)
{
	static t_line	line_row = {0};
	size_t			x_idx;
	size_t			y_idx;

	y_idx = 0;
	while (y_idx < map->max_row)
	{
		line_row.start.y += pad;
		line_row.end.y += pad;
		x_idx = 0;
		while (x_idx < map->map[y_idx]->len - 1)
		{
			line_row.start.x += pad;
			line_row.end.x = line_row.start.x + pad;
			t_line	tmp = transforme(line_row);
			print_line(tmp);
			tmp.start.y -= (map->map[y_idx]->array[x_idx] * 7);
			tmp.end.y -= (map->map[y_idx]->array[x_idx] * 7);

			draw_line(tmp, img);

//			draw_line(line_row, img);
			x_idx += 1;
		}
		line_row.start.x = 0;
		line_row.end.x = 0;
		y_idx += 1;
	}
	line_row = (t_line){0};
}
*/

void	draw_col(int pad, t_map *map, t_image *img)
{
	static t_line	line_col = {0};
	t_line			tmp;
	size_t			x_idx;
	size_t			y_idx;

	y_idx = 0;
	while (y_idx < map->max_row)
	{
		x_idx = 0;
		line_col.end.y += pad;
		while (x_idx < map->map[y_idx]->len)
		{
//			line_col.start.x = line_col.end.x;

			tmp = transforme(line_col);
			tmp.start.y -= (map->map[y_idx]->array[x_idx] * 7);
			tmp.end.y -= (map->map[y_idx]->array[x_idx] * 7);
			draw_line(tmp, img);

			x_idx += 1;
			line_col.end.x += pad;
			line_col.start.x += pad;
		}
		line_col.start.y = line_col.end.y;
		line_col.start.x = 0;
		line_col.end.x = 0;
		y_idx += 1;
	}
}

void	draw_row(int pad, t_map *map, t_image *img)
{
	static t_line	line_row = {0};
	t_line			tmp;
	size_t			x_idx;
	size_t			y_idx;

	y_idx = 0;
	while (y_idx < map->max_row)
	{
		x_idx = 0;
		line_row.start.y += pad;
		line_row.end.y += pad;
		while (x_idx < map->map[y_idx]->len - 1)
		{
			line_row.end.x += pad;
			tmp = transforme(line_row);
			tmp.start.y -= (map->map[y_idx]->array[x_idx] * 7);
			tmp.end.y -= (map->map[y_idx]->array[x_idx] * 7);
			draw_line(tmp, img);
			line_row.start.x = line_row.end.x;
			x_idx += 1;
		}
		line_row.start.x = 0;
		line_row.end.x = 0;
		y_idx += 1;
	}
}

int	get_pad(t_map *map)
{
	int	x_pad;
	int	y_pad;

	x_pad = (WIDTH - (WIDTH / 10)) / map->max_col;
	y_pad = (HEIGHT - (HEIGHT / 10)) / map->max_row;
	if (y_pad < x_pad)
		return (y_pad);
	return (x_pad);
}

int	draw(void *input)
{
	t_data	*data;
//	int		pad;

	data = input;
/*
	pad = get_pad(data->map);
	draw_row(pad, data->map, data->mlx->img);
	draw_col(pad, data->map, data->mlx->img);
*/
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->win,
							data->mlx->img->data, 0, 0);
	return (0);
}

void	mlx_run(char *path, int width, int height, int	(*draw)(void*))
{
	t_data	*out;

	out = create_data(path, width, height);
	if (NULL == out)
		return ;

//	int pad = get_pad(out->map);
	int pad = 50;
	draw_row(pad, out->map, out->mlx->img);
	draw_col(pad, out->map, out->mlx->img);

	mlx_loop_hook(out->mlx->mlx, draw, out);
	mlx_loop(out->mlx->mlx);
	return(delete_data(out));
}


int	main(int ac, char *av[])
{
	if (ac == 2)
		mlx_run(av[1], WIDTH, HEIGHT, draw);
	return (0);
}
