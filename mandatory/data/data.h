/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:48:34 by yboudoui          #+#    #+#             */
/*   Updated: 2022/11/27 06:13:15 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include "mlx_utils.h"
# include "image.h"
# include "parsing.h"
# include "map.h"

typedef struct s_data {
	t_mlx	*mlx;
	t_map	*map;
	t_image	*img;
	t_vec2	center;
	float	pad;
	float	height;
	int		mode;
}	t_data;

void	delete_data(t_data *data);
t_data	*create_data(char *path, int width, int height);

#endif
