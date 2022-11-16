/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 14:51:33 by yboudoui          #+#    #+#             */
/*   Updated: 2022/11/16 15:00:28 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//http://www.cs.yale.edu/homes/aspnes/classes/223/notes.html
#include "fdf.h"

t_quad	lol = {
	{
	[0] = (t_vec2){150, 20},
	[1] = (t_vec2){300, 10},
	[2] = (t_vec2){50, 150},
	[3] = (t_vec2){200, 300},
	}
};

void	put_quad_corner(t_image *img, t_quad quad)
{
	int	index;

	index = 0;
	while (index < 4)
	{
		image_put_pixel(img, quad.point[index].x, quad.point[index].y, 0x00FFFFFF);
		index++;
	}
}

int	draw(void *input)
{
	t_data	*data;

	data = input;
	if (data->redraw == true)
	{
		image_clear(data->mlx->img);
		draw_image(data);
		data->redraw = false;
	}
	draw_quad(data->mlx->img, lol);
	put_quad_corner(data->mlx->img, lol);

	mlx_put_image_to_window(data->mlx->mlx, data->mlx->win,
		data->mlx->img->data, 0, 0);
	return (0);
}

int	mouse_event(int key, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (4 > key || key > 5)
		return (0);
	if (key == 4)
		data->pad += 0.05f;
	if (key == 5)
		data->pad -= 0.05f;
	data->redraw = true;
	return (0);
}

int	main(int ac, char *av[])
{
	t_data	*out;

	if (ac != 2)
		return (-1);
	out = create_data(av[1], WIDTH, HEIGHT);
	if (NULL == out)
		return (-2);
	mlx_mouse_hook(out->mlx->win, mouse_event, out);
	mlx_loop_hook(out->mlx->mlx, draw, out);
	mlx_loop(out->mlx->mlx);
	return (delete_data(out), 0);
}
