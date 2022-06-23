/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 14:51:33 by yboudoui          #+#    #+#             */
/*   Updated: 2022/06/21 20:22:40 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(void)
{
	t_mlx	mlx;
	t_line	line;
	t_line	b;

	mlx = init("Hello world", 1920, 1080);

	line = new_line(1920/2, 100, 1920/2, -980);
	b = new_line(200, 1080/2, 1720, 1080 / 2);

	ft_put_pixel(&mlx, &line);
	ft_put_pixel(&mlx, &b);

	mlx_loop(mlx.mlx);
}
