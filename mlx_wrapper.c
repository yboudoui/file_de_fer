/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_wrapper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:26:16 by yboudoui          #+#    #+#             */
/*   Updated: 2022/06/21 19:59:44 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"

void	ft_put_pixel(t_mlx *mlx, void *handler)
{
	t_handler	*h;

	h = handler;
	void	func(void *pixel)
	{
		t_pixel	*pix;

		pix = pixel;
		mlx_pixel_put(mlx->mlx, mlx->win,
				pix->position.x, pix->position.y,
				pix->color);
	}
	h->draw(h, func);
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
	return (out);
}
