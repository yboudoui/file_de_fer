/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:33:34 by yboudoui          #+#    #+#             */
/*   Updated: 2022/11/16 17:25:49 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "my_mlx.h"
# include "parsing.h"

# define WIDTH 400
# define HEIGHT 600

# include <math.h>

t_vec2	transforme_vec2(t_vec2 in);
t_vec2	center_screen(t_vec2 in);
t_vec2	center_map(t_map *map, int pad, t_vec2 in);
void	draw_image(t_data *data);

#endif
