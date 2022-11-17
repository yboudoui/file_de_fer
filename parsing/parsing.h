/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 16:54:47 by yboudoui          #+#    #+#             */
/*   Updated: 2022/11/17 18:10:02 by yboudoui         ###   ########.fr       */
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
# include "map.h"

t_int_array	*atoi_words(char **words);
t_map		*parse_map(char *path);

#endif
