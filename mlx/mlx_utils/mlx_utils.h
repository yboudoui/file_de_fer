/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:00:50 by yboudoui          #+#    #+#             */
/*   Updated: 2022/11/24 16:48:26 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_H
# define MLX_UTILS_H

# include "mlx.h"
# include "mlx_int.h"
# include "image.h"

typedef struct s_image	t_image;

typedef struct s_keyboard {
	bool	control_key;
	bool	escape;
}	t_keyboard;

typedef struct s_mouse {
	t_vec2	pos;
	bool	scrol_up;
	bool	scrol_down;
}	t_mouse;

typedef struct s_mlx_event {
	t_keyboard	keyboard;
	t_mouse		mouse;
}	t_event;

typedef struct s_mlx {
	void	*mlx;
	void	*win;
	t_image	*img;
	t_event	event;
}	t_mlx;

void	event_handler(t_mlx *mlx);
t_mlx	*create_mlx(char *title, int width, int height);
void	delete_mlx(void *data);
#endif
