/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_words.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:48:12 by yboudoui          #+#    #+#             */
/*   Updated: 2022/11/14 17:40:21 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	replace(char *str)
{
	while (*str)
	{
		if (*str == ',')
			*str = '\0';
		str++;
	}
}

t_int_array	*atoi_words(char **words)
{
	t_int_array	*out;
	char		*tmp;
	size_t		count;

	count = 0;
	while (words[count])
		count += 1;
	out = alloc_int_array(count);
	if (NULL == out)
		return (NULL);
	count = 0;
	while (count < out->len)
	{
		tmp = words[count];
		replace(tmp);
		if (false == ft_atoi_to(&tmp, &(out->array[count])))
			return (free_int_array(out), NULL);
		count += 1;
	}
	return (out);
}
