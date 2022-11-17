/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 14:52:34 by yboudoui          #+#    #+#             */
/*   Updated: 2022/11/07 18:53:16 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

t_list	*read_file(char *path, int oflag)
{
	int		fd;
	char	*line;
	t_list	*out;

	fd = open(path, oflag);
	if (fd < 0)
		return (NULL);
	out = NULL;
	while (true)
	{
		line = get_next_line(fd);
		if (NULL == line)
			break ;
		if (false == lst_create_back(&out, line))
		{
			close(fd);
			return (lst_clear(&out, free), NULL);
		}
	}
	close(fd);
	return (out);
}
