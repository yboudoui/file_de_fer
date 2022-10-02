/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 16:52:03 by yboudoui          #+#    #+#             */
/*   Updated: 2022/10/02 18:22:41 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_map	*map_alloc(size_t count)
{
	t_map	*out;

	out = ft_calloc(1, sizeof(t_map));
	if (NULL == out)
		return (map_free(out), NULL);
	out->map = ft_calloc(count, sizeof(int *));
	if (NULL == out->map)
		return (map_free(out), NULL);
	return (out->max_y = count, out);
}

void	map_free(void *map)
{
	t_map	*data;
	size_t	index;

	data = map;
	if (!data || !data->map)
		return (free(data));
	index = data->max_y;
	while (index--)
		free(data->map[index]);
	return (free(data->map), free(data));
}

bool	ft_map(void *in, bool (*func)(void *, void *), void *out)
{
	size_t		index;

	index = data.size;
	if (!ft_new_1D_int(out, index))
		return (false);
	while (index--)
		if (!ft_atoi(out->array[index], data.array[index]))
			return (false);
	return (true);
}

t_map	*map_parse(t_arg arg)
{
	int		*int_ar;
	char	*chr_ar;
	t_map	*out;
	size_t	index;

	index = arg.count;
	out = map_alloc(index);
	while (out && index--)
	{
		int_ar = out->map[index];
		chr_ar = ft_split(arg.value[index], ft_isspace);
		if (!ft_map(int_ar, ft_atoi_to, chr_ar))
			return (map_free(out), NULL);
	}
	return (out);
}
