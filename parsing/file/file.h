/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 14:50:54 by yboudoui          #+#    #+#             */
/*   Updated: 2022/11/06 14:59:53 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H

# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include "get_next_line.h"
# include "lst.h"

t_list	*read_file(char *path, int oflag);

#endif
