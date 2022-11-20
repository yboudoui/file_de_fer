/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:58:45 by yboudoui          #+#    #+#             */
/*   Updated: 2022/11/20 17:23:03 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "int_array.h"
# include "utils.h"
# include "vec2.h"

typedef struct s_map {
	size_t		max_row;
	size_t		max_col;
	int			min_height;
	int			max_height;
	int			height;
	t_int_array	**map;
}	t_map;
/*
typedef struct {
	t_pixel	**map;
}
*/
t_map	*alloc_map(size_t len);
void	free_map(void *data);

#endif
