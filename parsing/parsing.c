/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 16:52:03 by yboudoui          #+#    #+#             */
/*   Updated: 2022/11/07 21:09:00 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	*parse_line(void *data)
{
	char		*line;
	char		*trimed;
	char		**splited;
	t_int_array	*output;
	size_t		index;

	line = data;
	if (NULL == line)
		return (NULL);
	trimed = ft_strtrim(line, "\n");
	if (NULL == trimed)
		return (NULL);
	splited = ft_split(trimed, ' ');
	free(trimed);
	if (NULL == splited)
		return (NULL);
	output = atoi_words(splited);
	index = 0;
	while (splited[index])
		free(splited[index++]);
	free(splited);
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

t_map	*alloc_map(size_t len)
{
	t_map	*output;

	output = ft_calloc(1, sizeof(t_map));
	if (NULL == output)
		return (NULL);
	output->max_row = len;
	output->map = ft_calloc(len + 1, sizeof(t_int_array*));
	if (NULL == output->map)
		return (free(output), NULL);
	return (output);
}

void	free_map(void *data)
{
	t_map	*input;
	size_t	index;

	if (NULL == data)
		return ;
	index = 0;
	input = data;
	while (input->map[index])
		free_int_array(input->map[index++]);
	free(input->map);
	free(data);
}

t_map	*parse_map(char *path)
{
	t_list	*lst;
	t_map	*output;
	t_list	*current;
	size_t	index;

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
	return (lst_clear(&lst, NULL), output);
}
