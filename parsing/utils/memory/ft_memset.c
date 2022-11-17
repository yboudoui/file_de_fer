/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <yboudoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:52:42 by yboudoui          #+#    #+#             */
/*   Updated: 2022/11/17 11:10:51 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*ptr;

	ptr = s;
	while (n--)
		*ptr++ = c;
	return (s);
}

void	ft_bzero(void *s, size_t n)
{
	__int128_t	*big_int;
	char		*ptr;

	big_int = s;
	while (n > 16)
	{
		(*big_int++) = 0;
		n -= 16;
	}
	ptr = s + n;
	while (n--)
		*ptr++ = 0;
}
