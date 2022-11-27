/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:58:45 by yboudoui          #+#    #+#             */
/*   Updated: 2022/11/24 17:24:14 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "int_array.h"
# include "lst.h"
# include "utils.h"
# include "vec2.h"
# include "color.h"

typedef struct s_vec3i {
	int	x;
	int	y;
	int	z;
}	t_vec3i;

typedef struct s_map {
	t_vec3i		size;
	t_int_array	*data;
	t_int_array	*color;
	t_color		palette[3];
}	t_map;

int		map_get_height(t_map *map, t_vec2 pos);
int		map_get_color(t_map *map, t_vec2 pos);
t_map	*init_map(t_list *lst);
void	free_map(t_map *input);

#endif
