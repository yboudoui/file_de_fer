/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:45:53 by yboudoui          #+#    #+#             */
/*   Updated: 2022/11/15 17:36:41 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_mlx.h"

static int	close_callback(int keycode, void *data)
{
	t_mlx	*input;

	input = data;
	(void)keycode;
	mlx_loop_end(input->mlx);
	return (0);
}

t_mlx	*create_mlx(char *title, int width, int height)
{
	t_mlx	*out;

	out = malloc(sizeof(t_mlx));
	if (NULL != out)
	{
		out->mlx = mlx_init();
		if (NULL == out->mlx)
			return (free(out), NULL);
		out->win = mlx_new_window(out->mlx, width, height, title);
		if (NULL == out->win)
			return (delete_mlx(out), NULL);
		out->img = image_new(out, width, height);
		if (NULL == out->img)
			return (delete_mlx(out), NULL);
		mlx_hook(out->win, 2, 1L << 0, close_callback, out);
	}
	return (out);
}

void	delete_mlx(void *data)
{
	t_mlx	*input;

	if (NULL == data)
		return ;
	input = data;
	delete_image(input->img);
	mlx_destroy_window(input->mlx, input->win);
	mlx_destroy_display(input->mlx);
	free(input->mlx);
	free(input);
}
