/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:20:32 by yboudoui          #+#    #+#             */
/*   Updated: 2022/10/02 15:03:30 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_H
# define LINE_H

# include "mlx_wrapper.h"
# include "vec2.h"

typedef struct s_line {
	t_vec2	start;
	t_vec2	end;
}	t_line;

t_line		ft_line(t_vec2 start, t_vec2 end);
t_mlx_obj	ft_line_obj(t_line *line);

#endif
