/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:59:52 by yboudoui          #+#    #+#             */
/*   Updated: 2022/11/24 18:05:48 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static void	update_min_max(t_map *map)
{
	int		min;
	int		max;
	size_t	index;

	if (NULL == map)
		return ;
	get_min_max(*map->data, &min, &max);
	map->size.z = (max - min);
	index = 0;
	while (index < map->data->len)
	{
		map->data->array[index] += (-min);
		index++;
	}
}

static bool	check_lst(t_list *lst, t_vec3i *size)
{
	t_int_array	*tmp;

	if (!lst || !lst->content || !size)
		return (false);
	(*size) = (t_vec3i){0};
	tmp = lst->content;
	size->x = tmp->len;
	while (lst)
	{
		tmp = lst->content;
		if (NULL == tmp || (int)tmp->len != size->x)
			return (false);
		size->y += 1;
		lst = lst->next;
	}
	if (!size->x || !size->y)
		return (false);
	return (true);
}

t_map	*init_map(t_list *lst)
{
	t_map		*out;
	size_t		index;
	t_int_array	*tmp;

	out = ft_calloc(1, sizeof(t_map));
	if (NULL == out || false == check_lst(lst, &out->size))
		return (free(out), NULL);
	out->data = alloc_int_array(out->size.x * out->size.y);
	out->color = alloc_int_array(out->size.x * out->size.y);
	index = 0;
	while (lst)
	{
		tmp = lst->content;
		ft_memcpy(&out->data->array[index],
			tmp->array, sizeof(int) * out->size.x);
		index += out->size.x;
		lst = lst->next;
	}
	out->palette[0].raw = 0xC52184;
	out->palette[1].raw = 0xF9B4ED;
	out->palette[2].raw = 0x02111B;
	return (update_min_max(out), out);
}

void	free_map(t_map *input)
{
	if (NULL == input)
		return ;
	free_int_array(input->data);
	free_int_array(input->color);
	free(input);
}
