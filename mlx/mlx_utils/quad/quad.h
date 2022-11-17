/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quad.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:35:23 by yboudoui          #+#    #+#             */
/*   Updated: 2022/11/17 18:34:31 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUAD_H
# define QUAD_H

# include <limits.h>
# include "line.h"

typedef struct s_quad {
	t_vec2	point[4];
}	t_quad;

void	draw_quad(t_image *img, t_quad quad);
void	draw_empty_quad(t_image *img, t_quad quad);
#endif
