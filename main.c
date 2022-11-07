/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 14:51:33 by yboudoui          #+#    #+#             */
/*   Updated: 2022/11/07 21:43:33 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//http://www.cs.yale.edu/homes/aspnes/classes/223/notes.html
#include "my_mlx.h"
#include "parsing.h"

#define WIDTH 1900
#define HEIGHT 800

#include <stdio.h>

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
		while (x_idx < map->map[y_idx]->len)
		{
			line_col.start.x += pad;
			line_col.end.x += pad;
			draw_line(line_col, img);
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
			draw_line(line_row, img);
			x_idx += 1;
		}
		line_row.start.x = 0;
		line_row.end.x = 0;
		y_idx += 1;
	}
	line_row = (t_line){0};
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
	int		pad;

	data = input;
	pad = get_pad(data->map);
	draw_row(pad, data->map, data->mlx->img);
	draw_col(pad, data->map, data->mlx->img);
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
