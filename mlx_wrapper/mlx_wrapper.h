/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_wrapper.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:23:20 by yboudoui          #+#    #+#             */
/*   Updated: 2022/10/02 13:28:36 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_WRAPPER_H
# define MLX_WRAPPER_H

# include "mlx_linux/mlx.h"
# include "mlx_linux/mlx_int.h"
# include "mlx_obj.h"

# include "stdbool.h"
# include "vec2.h"
# include "line.h"
/*
typedef union __attribute__ ((__transparent_union__))
{
	int	data;
}	t_color;
*/
typedef int		t_color;
typedef void	(*t_fp_put_pixel)(t_vec2, t_color);

bool	mlx_wrapper_init(void);
void	mlx_wrapper_put_pixel(t_vec2 pos, t_color color);

typedef struct s_window {
	void	*window;
	t_vec2	size;
}	t_window;

void	clear(void);
t_window	window(char *title, int width, int height);
void		use_window(t_window win);
int			close(int keycode);
void		window_put(t_mlx_obj obj);
void		add_hook(int x_event, int x_mask, int (*func)(), void *param);
void		add_loop_hook(int (*func)(), void *data);
void		start_loop(void);
void		free_all_mlx(void);
#endif
