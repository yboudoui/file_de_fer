/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:13:05 by yboudoui          #+#    #+#             */
/*   Updated: 2022/11/17 18:16:02 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line.h"

t_bresenham_data	bresenham_data_init(t_vec2 start, t_vec2 end)
{
	t_bresenham_data	out;

	if (start.y > end.y)
	{
		out.start = end;
		out.end = start;
	}
	else
	{
		out.start = start;
		out.end = end;
	}
	out.current = out.start;
	out.derivative = (t_vec2){
		.x = abs(out.end.x - out.start.x),
		.y = -abs(out.end.y - out.start.y)
	};
	out.slop = cmp_vec2(out.end, out.start);
	out.error = out.derivative.x + out.derivative.y;
	return (out);
}

t_vec2	bresenham_data_update(t_bresenham_data *in)
{
	t_vec2	out;

	out = (t_vec2){0};
	in->difference = (in->error * 2);
	if (in->difference > in->derivative.y)
	{
		in->error += in->derivative.y;
		out.x = in->slop.x;
	}
	if (in->difference < in->derivative.x)
	{
		in->error += in->derivative.x;
		out.y = in->slop.y;
	}
	return (out);
}

static bool	bresenham_data_done(t_bresenham_data in)
{
	return (in.current.x == in.end.x && in.current.y == in.end.y);
}

void	draw_line(t_image *img, int color, t_vec2 start, t_vec2 end)
{
	t_bresenham_data	brd;

	brd = bresenham_data_init(start, end);
	while (1)
	{
		image_put_pixel(img, brd.current.x, brd.current.y, color);
		if (bresenham_data_done(brd))
			break ;
		brd.current = add_vec2(brd.current, bresenham_data_update(&brd));
	}
}
