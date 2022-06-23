/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:26:50 by yboudoui          #+#    #+#             */
/*   Updated: 2022/06/23 07:34:57 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line.h"

void	ft_draw(t_line *line, void *handler)
{
	t_pixel	pixel;
	t_vec2	d, s;
	int	error;
	int	e2;

	pixel.color = 0x00FF0000;
	d.x = abs(line->end.x - line->start.x);
	d.y = -abs(line->end.y - line->start.y);
	s = cmp_vec2(line->start, line->end);
	error = d.x + d.y;
	pixel.position = line->start;
	while(pixel.position.x - line->end.x - pixel.position.y - line->end.y)
	{
		((t_draw *)handler)->put_pixel(handler, &pixel);
		e2 = 2 * error;
		error += (d.y * (e2 > d.y));
		error += (d.x * (e2 < d.x));
		pixel.position.x += (s.x * (e2 > d.y));
		pixel.position.y += (s.y * (e2 < d.x));
	}
}

t_line	new_line(int x1, int y1, int x2, int y2)
{
	t_line	out;

	out.start = (t_vec2){x1, y1};
	out.end = (t_vec2){x2 , y2};
	out.draw = &ft_draw;
	return (out);
}
