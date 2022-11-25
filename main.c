/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 14:51:33 by yboudoui          #+#    #+#             */
/*   Updated: 2022/11/24 18:03:48 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//http://www.cs.yale.edu/homes/aspnes/classes/223/notes.html
#include "fdf.h"

bool	update_state(t_data *data)
{
	if (data->mlx->event.keyboard.escape == true)
		return (mlx_loop_end(data->mlx->mlx), false);
	if (data->mlx->event.keyboard.control_key)
	{
		if (data->mlx->event.mouse.scrol_up)
			data->height += 0.03f;
		if (data->mlx->event.mouse.scrol_down)
			data->height -= 0.03f;
		data->mlx->event.mouse.scrol_up = false;
		data->mlx->event.mouse.scrol_down = false;
		return (true);
	}
	else
	{
		if (data->mlx->event.mouse.scrol_up)
			data->pad *= (1.5f);
		if (data->mlx->event.mouse.scrol_down)
			data->pad *= (0.5f);
		if (data->pad < 1.0f)
			data->pad = 1.0f;
		data->mlx->event.mouse.scrol_up = false;
		data->mlx->event.mouse.scrol_down = false;
		return (true);
	}
	return (false);
}

int	draw(t_data *data)
{
	data->center = data->mlx->event.mouse.pos;
	if (false == update_state(data))
		return (-1);
	draw_image(data);
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->win,
		data->img->data, 0, 0);
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
	mlx_loop_hook(out->mlx->mlx, draw, out);
	mlx_loop(out->mlx->mlx);
	return (delete_data(out), 0);
}
