/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 14:51:33 by yboudoui          #+#    #+#             */
/*   Updated: 2022/11/26 14:26:14 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//http://www.cs.yale.edu/homes/aspnes/classes/223/notes.html
#include "fdf.h"

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
