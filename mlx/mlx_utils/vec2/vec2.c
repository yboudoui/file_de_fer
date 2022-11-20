/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:25:11 by yboudoui          #+#    #+#             */
/*   Updated: 2022/11/20 19:16:59 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec2.h"

int	cmp(int a, int b)
{
	return ((a > b) - (a < b));
}

t_vec2	cmp_vec2(t_vec2 a, t_vec2 b)
{
	t_vec2	out;

	out.x = cmp(a.x, b.x);
	out.y = cmp(a.y, b.y);
	return (out);
}

int	is_equal(t_vec2 a, t_vec2 b)
{
	t_vec2	tmp;

	tmp.x = 0;
	tmp.y = 0;
	tmp = cmp_vec2(a, b);
	return (!tmp.x && !tmp.y);
}

t_vec2	substract_vec2(t_vec2 a, t_vec2 b)
{
	t_vec2	out;

	out.x = a.x - b.x;
	out.y = a.y - b.y;
	return (out);
}

t_vec2	mul_vec2(t_vec2 a, t_vec2 b)
{
	t_vec2	out;

	out.x = a.x * b.x;
	out.y = a.y * b.y;
	return (out);
}

t_vec2	add_vec2(t_vec2 a, t_vec2 b)
{
	t_vec2	out;

	out.x = a.x + b.x;
	out.y = a.y + b.y;
	return (out);
}