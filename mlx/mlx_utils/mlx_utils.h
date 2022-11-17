/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:00:50 by yboudoui          #+#    #+#             */
/*   Updated: 2022/11/17 18:40:01 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_H
# define MLX_UTILS_H

# include "mlx.h"
# include "mlx_int.h"
# include "image.h"

typedef struct s_image	t_image;
typedef struct s_mlx {
	void	*mlx;
	void	*win;
	t_image	*img;
}	t_mlx;

t_mlx	*create_mlx(char *title, int width, int height);
void	delete_mlx(void *data);
#endif
