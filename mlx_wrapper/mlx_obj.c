/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_obj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 08:02:12 by yboudoui          #+#    #+#             */
/*   Updated: 2022/10/02 09:26:21 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_obj.h"

t_mlx_obj	new_mlx_obj(const t_mlx_obj_vtable *vtable, void *data)
{
	return ((t_mlx_obj [2]){{data, vtable}, {0}}[(!data || !vtable)]);
}
