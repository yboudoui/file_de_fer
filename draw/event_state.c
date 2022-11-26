/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:22:47 by yboudoui          #+#    #+#             */
/*   Updated: 2022/11/26 14:36:54 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static bool	update_control(t_data *data)
{
	if (data->mlx->event.mouse.scrol_up)
		data->height += 0.03f;
	if (data->mlx->event.mouse.scrol_down)
		data->height -= 0.03f;
	data->mlx->event.mouse.scrol_up = false;
	data->mlx->event.mouse.scrol_down = false;
	return (true);
}

static bool	update_scrol(t_data *data)
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

bool	update_state(t_data *data)
{
	if (data->mlx->event.keyboard.enter)
	{
		data->mode += 1;
		if (data->mode > 2)
			data->mode = 0;
		data->mlx->event.keyboard.enter = false;
		return (true);
	}
	if (data->mlx->event.keyboard.escape == true)
		return (mlx_loop_end(data->mlx->mlx), false);
	if (data->mlx->event.keyboard.control_key)
		return (update_control(data));
	else
		return (update_scrol(data));
	return (false);
}
