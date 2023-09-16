/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 16:52:03 by yboudoui          #+#    #+#             */
/*   Updated: 2022/11/24 18:10:50 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	*parse_line(char *line)
{
	char		*trimed;
	char		**splited_space;
	t_int_array	*output;

	if (NULL == line)
		return (NULL);
	trimed = ft_strtrim(line, "\n");
	if (NULL == trimed)
		return (NULL);
	splited_space = ft_split(trimed, ' ');
	free(trimed);
	if (NULL == splited_space)
		return (NULL);
	output = atoi_words(splited_space);
	free_split(splited_space);
	return (output);
}

static void	interpolate_height(t_map *map)
{
	size_t			index;
	float			height;

	if (NULL == map)
		return ;
	index = 0;
	while (index < map->data->len)
	{
		height = map->data->array[index];
		height /= map->size.z;
		if (map->size.z == 0)
			height = 0;
		map->color->array[index] = interpolate_color(
				map->palette[0], height, map->palette[1]).raw;
		index++;
	}
}

t_map	*parse_map(char *path)
{
	t_list	*lines;
	t_map	*output;

	lines = read_file(path, O_RDONLY, parse_line, free_int_array);
	output = init_map(lines);
	interpolate_height(output);
	return (lst_clear(&lines, free_int_array), output);
}
