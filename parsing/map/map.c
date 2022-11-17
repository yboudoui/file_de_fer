/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:59:52 by yboudoui          #+#    #+#             */
/*   Updated: 2022/11/17 18:00:13 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

t_map	*alloc_map(size_t len)
{
	t_map	*output;

	output = ft_calloc(1, sizeof(t_map));
	if (NULL == output)
		return (NULL);
	output->max_row = len;
	output->map = ft_calloc(len + 1, sizeof(t_int_array *));
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
