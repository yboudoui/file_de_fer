/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:00:38 by yboudoui          #+#    #+#             */
/*   Updated: 2022/11/27 06:29:03 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include <math.h>

void	delete_data(t_data *data)
{
	if (NULL == data)
		return ;
	delete_image(data->img);
	free_map(data->map);
	delete_mlx(data->mlx);
	free(data);
}

static double	get_pad(t_image *img, t_map *map)
{
	double	hypothenuse;
	double	min;

	hypothenuse = sqrt(pow(map->size.x, 2) + pow(map->size.y, 2));
	min = img->height;
	if (img->width < img->height)
		min = img->width;
	min -= 20;
	return (min / hypothenuse);
}

static bool	file_format(char *path)
{
	size_t	index;

	index = 0;
	while (path[index])
		index++;
	return (ft_strncmp(&path[index - 4], ".fdf", 4) == 0);
}

t_data	*create_data(char *path, int width, int height)
{
	t_data	*out;

	out = ft_calloc(1, sizeof(t_data));
	if (NULL == out)
		return (NULL);
	if (false == file_format(path))
		return (delete_data(out), NULL);
	out->map = parse_map(path);
	if (NULL == out->map)
		return (delete_data(out), NULL);
	out->mlx = create_mlx(path, width, height);
	if (NULL == out->mlx)
		return (delete_data(out), NULL);
	out->img = image_new(out->mlx, width, height);
	out->pad = get_pad(out->img, out->map);
	out->height = 0.1f;
	out->center = (t_vec2){width / 2, height / 2};
	return (out);
}
