/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_obj.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 07:54:42 by yboudoui          #+#    #+#             */
/*   Updated: 2022/10/02 09:40:28 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_OBJ_H
# define MLX_OBJ_H

typedef struct s_mlx_obj		t_mlx_obj;
typedef struct s_mlx_obj_vtable	t_mlx_obj_vtable;

struct s_mlx_obj_vtable {
	void	(*free)(void *);
	void	(*draw)(void *);
};

struct s_mlx_obj {
	void					*data;
	const t_mlx_obj_vtable	*vtable;
};

t_mlx_obj	new_mlx_obj(const t_mlx_obj_vtable *vtable, void *data);
#endif
