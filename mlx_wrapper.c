/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_wrapper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:26:16 by yboudoui          #+#    #+#             */
/*   Updated: 2022/06/23 07:37:44 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"

void	FT_pixel(void *data, t_pixel *pix)
{
	t_mlx	*mlx;

	mlx = data;
	mlx_pixel_put(mlx->mlx, mlx->win,
			pix->position.x, pix->position.y,
			pix->color);
}

t_mlx	init(char *title, int width, int height)
{
	t_mlx	out;

	out = (t_mlx){0};
	if (!title || !width || !height)
		return (out);
	out.mlx = mlx_init();
	out.win = mlx_new_window(out.mlx, width, height, title);
	out.win_size = (t_vec2){width, height};
	out.draw.put_pixel = &FT_pixel;
	return (out);
}
