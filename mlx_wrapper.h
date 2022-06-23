/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_wrapper.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:23:20 by yboudoui          #+#    #+#             */
/*   Updated: 2022/06/21 20:02:19 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_WRAPPER_H
# define MLX_WRAPPER_H

#include "mlx_linux/mlx.h"
#include "mlx_linux/mlx_int.h"
#include "pixel.h"

typedef void (*t_generique)(void *, void (*)(void *));

typedef struct s_mlx {
	void	*mlx;
	void	*win;
	t_vec2	win_size;
}	t_mlx;

typedef struct s_handler {
	t_generique	draw;
}	t_handler;

void	ft_put_pixel(t_mlx *mlx, void *handler);
t_mlx	init(char *title, int width, int height);
#endif
