/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:13:05 by yboudoui          #+#    #+#             */
/*   Updated: 2022/11/16 18:06:38 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_mlx.h"

typedef struct s_bresenham_data {
	t_vec2	derivative;
	t_vec2	slop;
	int		error;
	int		difference;
	t_vec2	start;
	t_vec2	end;
	t_vec2	current;
}	t_bresenham_data;

static t_bresenham_data bresenham_data_init(t_vec2 start, t_vec2 end)
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

static t_vec2	bresenham_data_update(t_bresenham_data *in)
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

	
	if (in->current.x == in->end.x)
		return (true);

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

void	draw_line_step(t_image *img, t_bresenham_data *brd, int **tab)
{
	(void)img;
	if (brd->start.y >= brd->current.y || brd->current.y > brd->end.y)
	{
		brd->current.y += 1;
		return ;
	}
	(*tab)[0] = brd->current.x;
	while (1)
	{
		if (custom_bresenham_data_update(brd))
			break ;
	}
	(*tab)[1] = brd->current.x;
	brd->current.y += 1;
	(*tab) += 2;
}

void	draw_quad(t_image *img, t_quad quad)
{
	t_bresenham_data	*brd;
	int	loop;
	int	min;
	int	max;
	int	*tab;
	int	max_it;
	int	index;
	int	*tmp;

	max_it = max_iteration(quad, &min, &max);

	brd = (t_bresenham_data [4]) {
	[0] = bresenham_data_init(quad.point[0], quad.point[1]),
	[1] = bresenham_data_init(quad.point[1], quad.point[3]),
	[2] = bresenham_data_init(quad.point[3], quad.point[2]),
	[3] = bresenham_data_init(quad.point[2], quad.point[0]),
	};
	index = 0;
	while (index < 4)
		brd[index++].current.y = min;
	tab = ft_calloc(max_it, (sizeof(int) * 8));
	if (NULL == tab)
		return ;
	tmp = tab;
	index = 0;
	while (index < max_it)
	{
		loop = 0;
		while (loop < 4)
			draw_line_step(img, &brd[loop++], &tmp);
		index++;
	}
	tmp = tab;
	index = min;
	while (index < max)
	{
		draw_line(img, 0x2424243 , (t_vec2){tmp[1] + 1, index}, (t_vec2){tmp[2] - 1, index});
		tmp += 4;
		index++;
	}
	int	col = 0xF5CB5C;
	draw_line(img, col, quad.point[0], quad.point[1]);
	draw_line(img, col, quad.point[1], quad.point[3]);
	draw_line(img, col, quad.point[3], quad.point[2]);
	draw_line(img, col, quad.point[2], quad.point[0]);
	free(tab);
}
