/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 16:54:47 by yboudoui          #+#    #+#             */
/*   Updated: 2022/11/14 18:45:41 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "str.h"
# include "file.h"
# include "utils.h"
# include "int_array.h"
# include "lst.h"
# include "vec2.h"

typedef struct s_map {
	size_t		max_row;
	size_t		max_col;
	t_vec2		max_height;
	t_int_array	**map;
}	t_map;

t_int_array	*atoi_words(char **words);
t_map		*parse_map(char *path);
void		free_map(void *data);

#endif
