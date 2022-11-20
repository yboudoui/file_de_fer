/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:00:38 by yboudoui          #+#    #+#             */
/*   Updated: 2022/11/20 20:40:08 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

//#define SCALE 2.7

void	delete_data(void *data)
{
	t_data	*input;

	input = data;
	delete_image(input->img);
	free_map(input->map);
	delete_mlx(input->mlx);
	free(input);
}

t_data	*create_data(char *path, int width, int height)
{
	t_data	*out;

	out = ft_calloc(1, sizeof(t_data));
	if (NULL == out)
		return (NULL);
	out->map = parse_map(path);
	if (NULL == out->map)
		return (delete_data(out), NULL);
	out->mlx = create_mlx(path, width, height);
	if (NULL == out)
		return (delete_data(out), NULL);

	float SCALE = 2.7f;
	out->img = image_new(out->mlx, width * SCALE, height * SCALE);
	out->pad = 1;
	out->redraw = true;
	out->center = (t_vec2){
		out->img->width / 2, out->img->height / 2
	};
	return (out);
}
