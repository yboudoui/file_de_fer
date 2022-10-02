/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_wrapper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:26:16 by yboudoui          #+#    #+#             */
/*   Updated: 2022/10/02 13:28:27 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"

static void	*g_mlx;
static void	*g_win;

bool	mlx_wrapper_init(void)
{
	g_mlx = mlx_init();
	return (!!g_mlx);
}

void	mlx_wrapper_put_pixel(t_vec2 pos, t_color color)
{
	if (!g_mlx || !g_win)
		return ;
	mlx_pixel_put(g_mlx, g_win, pos.x, pos.y, color);
}

t_window	window(char *title, int width, int height)
{
	t_window	out;

	out = (t_window){0};
	if (!title || !width || !height)
		return (out);
	out.window = mlx_new_window(g_mlx, width, height, title);
	out.size = (t_vec2){width, height};
	return (out);
}

int	close(int keycode)
{
	(void)keycode;
	mlx_loop_end(g_mlx);
	return (0);
}

void	clear(void)
{
	mlx_clear_window(g_mlx, g_win);
}

void	free_all_mlx(void)
{
	mlx_destroy_window(g_mlx, g_win);
	mlx_destroy_display(g_mlx);
	free(g_mlx);
}

void	use_window(t_window win)
{
	g_win = win.window;
}

void	add_hook(int x_event, int x_mask, int (*func)(), void *param)
{
	mlx_hook(g_win, x_event, x_mask, func, param);
}

void	add_loop_hook(int (*func)(), void *data)
{
	mlx_loop_hook(g_mlx, func, data);
}

void	start_loop(void)
{
	mlx_loop(g_mlx);
}

void	window_put(t_mlx_obj obj)
{
	obj.vtable->draw(obj.data);
}
