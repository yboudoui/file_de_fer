/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 14:51:33 by yboudoui          #+#    #+#             */
/*   Updated: 2022/11/17 10:45:18 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//http://www.cs.yale.edu/homes/aspnes/classes/223/notes.html
#include "fdf.h"

int	draw(t_data *data)
{
	if (data->redraw == true)
	{
		image_clear(data->mlx->img);
		draw_image(data);
		data->redraw = false;
	}
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

int	mousse(int x, int y, t_data *data)
{
	data->center = (t_vec2){x, y};
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
	mlx_hook(out->mlx->win, 6, 1L << 8, mousse, out);
	mlx_loop_hook(out->mlx->mlx, draw, out);
	mlx_loop(out->mlx->mlx);
	return (delete_data(out), 0);
}
