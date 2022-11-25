/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:05:37 by yboudoui          #+#    #+#             */
/*   Updated: 2022/11/24 18:05:57 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

inline int	map_get_height(t_map *map, t_vec2 pos)
{
	pos.y *= map->size.x;
	return (map->data->array[pos.x + pos.y]);
}

inline int	map_get_color(t_map *map, t_vec2 pos)
{
	pos.y *= map->size.x;
	return (map->color->array[pos.x + pos.y]);
}
