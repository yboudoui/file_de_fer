/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:13:05 by yboudoui          #+#    #+#             */
/*   Updated: 2022/11/07 19:06:20 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_mlx.h"

t_line	ft_line(t_vec2 start, t_vec2 end)
{
	return ((t_line) {start, end});
}

void	draw_line(t_line line, t_image *img)
{
	t_vec2	d, s;
	int	error;
	int	e2;

	d.x = abs(line.end.x - line.start.x);
	d.y = -abs(line.end.y - line.start.y);
	s = cmp_vec2(line.end, line.start);
	error = d.x + d.y;
	while(1)
	{
		image_put_pixel(img, line.start.x, line.start.y, 0x00FF0000);
		if (line.start.x == line.end.x && line.start.y == line.end.y)
			break ;
		e2 = 2 * error;
		error += (d.y * (e2 > d.y)) + (d.x * (e2 < d.x));
		line.start.x += (s.x * (e2 > d.y));
		line.start.y += (s.y * (e2 < d.x));
	}
}
