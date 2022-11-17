/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:25:26 by yboudoui          #+#    #+#             */
/*   Updated: 2022/11/17 17:41:33 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "vec2.h"

t_vec2	transforme_vec2(t_vec2 in)
{
	t_vec2			out;

	out = (t_vec2){
		.x = (in.x - in.y),
		.y = ((in.x / 2) + (in.y / 2)),
	};
	return (out);
}

t_vec2	center_screen(t_vec2 in)
{
	in.x += WIDTH / 2;
	in.y += HEIGHT / 2;
	return (in);
}

t_vec2	center_map(t_map *map, int pad, t_vec2 in)
{
	in.x -= map->max_col / 2;
	in.y -= map->max_row / 2;
	in.x *= pad;
	in.y *= pad;
	return (in);
}
