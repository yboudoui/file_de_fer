/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:58:45 by yboudoui          #+#    #+#             */
/*   Updated: 2022/11/17 18:26:12 by yboudoui         ###   ########.fr       */
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
	t_vec2		max_height;
	t_int_array	**map;
}	t_map;

t_map	*alloc_map(size_t len);
void	free_map(void *data);

#endif
