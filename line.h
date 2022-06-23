/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:20:32 by yboudoui          #+#    #+#             */
/*   Updated: 2022/06/21 20:17:35 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_H
# define LINE_H

#include "pixel.h"

typedef void (*t_func)(void *);

typedef struct s_line {
	void	(*draw)(void *, t_func);
	t_vec2	start;
	t_vec2	end;
}	t_line;

t_line	new_line(int x1, int y1, int x2, int y2);

#endif
