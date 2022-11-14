/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 14:51:33 by yboudoui          #+#    #+#             */
/*   Updated: 2022/11/14 11:28:40 by yboudoui         ###   ########.fr       */
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

	out = (t_vec2){
		.x = (in.x - in.y),
		.y = ((in.x / 2) + (in.y / 2)),
	};
	out.x += 600;
	out.y += 200;
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

void	draw_row(int pad, t_map *map, t_image *img)
{
	t_vec2			start;
	t_vec2			end;
	t_line			tmp;
	size_t			x_idx;
	size_t			y_idx;

	end = transforme_vec2((t_vec2){0});
	y_idx = 0;
	while (y_idx < map->max_row)
	{
		x_idx = 0;
		end = transforme_vec2((t_vec2){0, y_idx * pad});
		while (x_idx < map->max_col)
		{
			start = end;
			end = transforme_vec2((t_vec2){x_idx * pad, y_idx * pad});
			end.y -= (map->map[y_idx]->array[x_idx] * 3);
			tmp = (t_line){.start = start, .end = end};

			draw_line(tmp, img);
			x_idx += 1;
		}
		y_idx += 1;
	}
}

void	draw_col(int pad, t_map *map, t_image *img)
{
	t_vec2			start;
	t_vec2			end;
	t_line			tmp;
	size_t			x_idx;
	size_t			y_idx;

	end = transforme_vec2((t_vec2){0});
	x_idx = 0;
	while (x_idx < map->max_col)
	{
		y_idx = 0;
		end = transforme_vec2((t_vec2){x_idx * pad, y_idx * pad});
		while (y_idx < map->max_row)
		{
			start = end;
			end = transforme_vec2((t_vec2){x_idx * pad, y_idx * pad});
			end.y -= (map->map[y_idx]->array[x_idx] * 3);
			tmp = (t_line){.start = start, .end = end};

			draw_line(tmp, img);
			y_idx += 1;
		}
		x_idx += 1;
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

	data = input;
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
	int pad = 5;
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
