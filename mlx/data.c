/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:00:38 by yboudoui          #+#    #+#             */
/*   Updated: 2022/11/15 18:23:56 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_mlx.h"

void	delete_data(void *data)
{
	t_data	*input;

	input = data;
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
	out->pad = 1;
	out->redraw = true;
	return (out);
}
