/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:56:15 by yboudoui          #+#    #+#             */
/*   Updated: 2022/06/23 07:33:14 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIXEL_H
# define PIXEL_H

#include "vec2/vec2.h"

typedef int				t_color;

typedef struct s_pixel {
	t_color	color;
	t_vec2	position;
}	t_pixel;

typedef struct draw {
	void (*put_pixel)(void *, t_pixel *);
}	t_draw;

#endif
