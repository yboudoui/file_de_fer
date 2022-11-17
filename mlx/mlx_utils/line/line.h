/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:33:11 by yboudoui          #+#    #+#             */
/*   Updated: 2022/11/17 18:16:32 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_H
# define LINE_H

# include <stdbool.h>
# include "vec2.h"
# include "image.h"

typedef struct s_bresenham_data {
	t_vec2	derivative;
	t_vec2	slop;
	int		error;
	int		difference;
	t_vec2	start;
	t_vec2	end;
	t_vec2	current;
}	t_bresenham_data;

t_bresenham_data	bresenham_data_init(t_vec2 start, t_vec2 end);
t_vec2				bresenham_data_update(t_bresenham_data *in);
void				draw_line(
						t_image *img, int color, t_vec2 start, t_vec2 end);
#endif
