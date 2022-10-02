/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 16:54:47 by yboudoui          #+#    #+#             */
/*   Updated: 2022/10/02 18:14:13 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

typedef struct s_arg {
	size_t	count;
	char	*value[];
}	t_arg;

typedef struct s_size {
	size_t	type;
	size_t	member;
}	t_size;

typedef void*	t_ptr;

typedef struct s_array {
	t_ptr	array;
	t_size	size;
}	t_array;

typedef struct s_matrix {
	t_array	array;
	t_size	size;
}	t_matrix;

typedef struct s_map {
	size_t		max_x;
	size_t		max_y;
	t_int_2D	map;
}	t_map;

#endif
