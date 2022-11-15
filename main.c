/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 14:51:33 by yboudoui          #+#    #+#             */
/*   Updated: 2022/11/15 18:24:55 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//http://www.cs.yale.edu/homes/aspnes/classes/223/notes.html
#include "fdf.h"

int	draw(void *input)
{
	t_data	*data;
	t_image	*img;
	size_t	size;

	data = input;
	if (data->redraw == false)
		return (0);
	img = data->mlx->img;
	size = (img->width - 1) * (img->bits_per_pixel / 8);
	size += (img->height - 1) * (img->line_length);
	ft_memset(img->addr, 0, size);
	draw_image(data);

	mlx_put_image_to_window(data->mlx->mlx, data->mlx->win,
		data->mlx->img->data, 0, 0);
	data->redraw = false;
	return (0);
}

#include <stdio.h>

int	mouse_event(int key, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (4 > key || key > 5)
		return (0);
	if (key == 4)
		data->pad += 0.01f;
	if (key == 5)
		data->pad -= 0.01f;
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
	printf("%p\n", out);
	mlx_mouse_hook(out->mlx->win, mouse_event, out);
	mlx_loop_hook(out->mlx->mlx, draw, out);
	mlx_loop(out->mlx->mlx);
	return (delete_data(out), 0);
}
