/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_quad.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:02:48 by yboudoui          #+#    #+#             */
/*   Updated: 2022/11/17 18:18:02 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quad.h"

#define COLOR 0x006400

void	draw_empty_quad(t_image *img, t_quad quad)
{
	draw_line(img, COLOR, quad.point[0], quad.point[1]);
	draw_line(img, COLOR, quad.point[1], quad.point[3]);
	draw_line(img, COLOR, quad.point[3], quad.point[2]);
	draw_line(img, COLOR, quad.point[2], quad.point[0]);
}
