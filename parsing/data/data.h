/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:48:34 by yboudoui          #+#    #+#             */
/*   Updated: 2022/11/17 18:25:21 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include "mlx_utils.h"
# include "parsing.h"
# include "map.h"

typedef struct s_data {
	t_mlx	*mlx;
	t_map	*map;
	bool	redraw;
	t_vec2	center;
	double	pad;
}	t_data;

void	delete_data(void *data);
t_data	*create_data(char *path, int width, int height);

#endif
