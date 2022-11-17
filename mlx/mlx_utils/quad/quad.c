/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quad.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:19:20 by yboudoui          #+#    #+#             */
/*   Updated: 2022/11/17 18:53:45 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quad.h"

static int	max_iteration(t_quad quad, int *min, int *max)
{
	size_t	index;

	index = 0;
	*min = INT_MAX;
	*max = INT_MIN;
	while (index < 4)
	{
		if (*min > quad.point[index].y)
			*min = quad.point[index].y;
		if (*max < quad.point[index].y)
			*max = quad.point[index].y;
		index++;
	}
	return (*max - *min);
}

static bool	custom_bresenham_data_update(t_bresenham_data *in)
{
	t_vec2	out;
	bool	stop;

	stop = false;
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
		stop = true;
	}
	in->current.x += out.x;
	return (stop);
}

bool	draw_line_step(t_bresenham_data *brd, int *tab)
{
	if (brd->start.y >= brd->current.y || brd->current.y > brd->end.y)
		return (brd->current.y += 1, false);
	tab[0] = brd->current.x;
	while (1)
		if (custom_bresenham_data_update(brd))
			break ;
	tab[1] = brd->current.x;
	return (brd->current.y += 1, true);
}

static void	init_bresenham_quad(t_bresenham_data data[4], t_quad quad, int min)
{
	int	index;

	data[0] = bresenham_data_init(quad.point[0], quad.point[1]);
	data[1] = bresenham_data_init(quad.point[1], quad.point[3]);
	data[2] = bresenham_data_init(quad.point[3], quad.point[2]);
	data[3] = bresenham_data_init(quad.point[2], quad.point[0]);
	index = 0;
	while (index < 4)
		data[index++].current.y = min;
}

void	draw_quad(t_image *img, t_quad quad)
{
	t_bresenham_data	brd[4];
	int					min;
	int					max;
	int					*index;
	int					tmp[4];

	max_iteration(quad, &min, &max);
	init_bresenham_quad(brd, quad, min);
	tmp[1] = quad.point[0].x;
	tmp[3] = quad.point[0].x;
	while (min < max)
	{
		index = (int [2]){0};
		while (index[0] < 4 && index[1] != 4)
		{
			if (draw_line_step(&brd[index[0]], &tmp[index[1]]))
				index[1] += 2;
			index[0]++;
		}
		image_put_horizontal_line(img, (int [2]){tmp[1], tmp[3]}, min, 0);
		min++;
	}
	draw_empty_quad(img, quad);
}
