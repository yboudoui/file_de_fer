/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 06:07:18 by yboudoui          #+#    #+#             */
/*   Updated: 2022/11/06 18:40:46 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "int_array.h"

t_int_array	*alloc_int_array(size_t len)
{
	t_int_array	*out;

	if (1 > len)
		return (NULL);
	out = ft_calloc(1, sizeof(t_int_array));
	if (NULL == out)
		return (NULL);
	out->len = len;
	out->array = ft_calloc(out->len, sizeof(int));
	if (NULL == out->array)
		return (free(out), NULL);
	return (out);
}

void	free_int_array(void *data)
{
	t_int_array	*input;

	if (NULL == data)
		return ;
	input = data;
	free(input->array);
	free(input);
}
