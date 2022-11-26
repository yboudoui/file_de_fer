/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:46:04 by yboudoui          #+#    #+#             */
/*   Updated: 2022/11/26 14:28:49 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utils.h"

static int	mouse_pos(int x, int y, t_mlx *data)
{
	data->event.mouse.pos = (t_vec2){x, y};
	return (0);
}

static int	key_press(int keycode, t_mlx *data)
{
	if (keycode == 65507 || keycode == 65508)
		data->event.keyboard.control_key = true;
	if (keycode == 65293)
		data->event.keyboard.enter = true;
	if (keycode == 65307)
		data->event.keyboard.escape = true;
	return (0);
}

static int	key_release(int keycode, t_mlx *data)
{
	if (keycode == 65507 || keycode == 65508)
		data->event.keyboard.control_key = false;
	if (keycode == 65293)
		data->event.keyboard.enter = false;
	if (keycode == 65307)
		data->event.keyboard.escape = false;
	return (0);
}

static int	mouse_press(int key, int x, int y, t_mlx *data)
{
	(void)x;
	(void)y;
	if (key == 4)
		data->event.mouse.scrol_up = true;
	if (key == 5)
		data->event.mouse.scrol_down = true;
	return (0);
}

void	event_handler(t_mlx *mlx)
{
	mlx_hook(mlx->win, 2, 1L << 0, key_press, mlx);
	mlx_hook(mlx->win, 3, 1L << 1, key_release, mlx);
	mlx_hook(mlx->win, 4, 1L << 2, mouse_press, mlx);
	mlx_hook(mlx->win, 6, 1L << 8, mouse_pos, mlx);
}
