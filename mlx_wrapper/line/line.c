/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:26:50 by yboudoui          #+#    #+#             */
/*   Updated: 2022/10/02 13:22:04 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line.h"

const int	g_color = 0x00FF0000;

static void	draw(void *data)
{
	t_line	line;
	t_vec2	d, s;
	int	error;
	int	e2;

	line = *((t_line*)data);
	d.x = abs(line.end.x - line.start.x);
	d.y = -abs(line.end.y - line.start.y);
	s = cmp_vec2(line.end, line.start);
	error = d.x + d.y;
	while(1)
	{
		mlx_wrapper_put_pixel(line.start, g_color);
		if (line.start.x == line.end.x && line.start.y == line.end.y)
			break ;
		e2 = 2 * error;
		error += (d.y * (e2 > d.y)) + (d.x * (e2 < d.x));
		line.start.x += (s.x * (e2 > d.y));
		line.start.y += (s.y * (e2 < d.x));
	}
}

t_line	ft_line(t_vec2 start, t_vec2 end)
{
	return ((t_line) {start, end});
}

static t_mlx_obj_vtable g_vtable = {free, draw};

t_mlx_obj	ft_line_obj(t_line *line)
{
	return ((t_mlx_obj){line, &g_vtable});
}
