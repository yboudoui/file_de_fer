/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 16:52:03 by yboudoui          #+#    #+#             */
/*   Updated: 2022/11/20 17:18:30 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	*parse_line(void *line)
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

static t_list	*parse_file(char *path)
{
	t_list		*output;
	t_list		*lines;

	lines = read_file(path, O_RDONLY);
	if (NULL == lines)
		return (NULL);
	output = lst_map(lines, parse_line, free_int_array);
	lst_clear(&lines, free);
	return (output);
}

int	max_height(t_int_array *input)
{
	size_t	index;
	int		max;

	index = 0;
	max = 0;
	while (index < input->len)
	{
		if (max < input->array[index])
			max = input->array[index];
		index++;
	}
	return (max);
}

void	set_min_max_height(t_map *map)
{
	size_t	index;
	int		min;
	int		max;

	if (NULL == map)
		return ;
	index = 0;
	while (index < map->max_row)
	{
		get_min_max(*map->map[index], &min, &max);
		if (map->min_height > min)
			map->min_height = min;
		if (map->max_height < max)
			map->max_height = max;
		index++;
	}
	map->height = (map->max_height - map->min_height);
}

t_map	*parse_map(char *path)
{
	t_list	*lst;
	t_map	*output;
	t_list	*current;
	int		index;

	lst = parse_file(path);
	if (NULL == lst)
		return (NULL);
	output = alloc_map(lst_size(lst));
	if (NULL == output)
		return (lst_clear(&lst, free_int_array), NULL);
	index = 0;
	current = lst;
	while (current)
	{
		output->map[index] = current->content;
		if (output->max_col < output->map[index]->len)
			output->max_col = output->map[index]->len;
		index += 1;
		current = current->next;
	}
	set_min_max_height(output);
	return (lst_clear(&lst, NULL), output);
}
