/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:23:22 by yboudoui          #+#    #+#             */
/*   Updated: 2022/06/20 17:28:43 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"

int	abs(int nb)
{
	return ((nb * (nb < 0)) + (nb * (nb >= 0)));
}

int	cmp(int a, int b)
{
	return ((a < b) - (a > b));
}

int	pow2(int nb)
{
	return (nb * nb);
}

int	is_hypotenus(int a, int b, int hypotenus)
{
	return (pow2(hypotenus) == pow2(a) + pow2(b));
}
