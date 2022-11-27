/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:33:34 by yboudoui          #+#    #+#             */
/*   Updated: 2022/11/26 14:27:54 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx_utils.h"
# include "parsing.h"
# include "data.h"
# include "image.h"
# include <math.h>

# define WIDTH 1920
# define HEIGHT 1080

# ifndef BONUS
#  define BONUS 0
# endif

t_vec2	transforme_vec2(t_vec2 in);
t_vec2	center_screen(t_vec2 in);
t_vec2	center_map(t_map *map, int pad, t_vec2 in);
void	draw_image(t_data *data);
bool	update_state(t_data *data);

#endif
