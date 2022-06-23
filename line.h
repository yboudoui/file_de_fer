/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:20:32 by yboudoui          #+#    #+#             */
/*   Updated: 2022/06/23 07:35:58 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_H
# define LINE_H

#include "pixel.h"

typedef struct s_line {
	void	(*draw)(struct s_line *, void *);
	t_vec2	start;
	t_vec2	end;
}	t_line;

void	ft_draw(t_line *line, void *handler);
t_line	new_line(int x1, int y1, int x2, int y2);

#endif
