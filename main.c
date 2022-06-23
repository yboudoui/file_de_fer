/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 14:51:33 by yboudoui          #+#    #+#             */
/*   Updated: 2022/06/23 07:37:55 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//http://www.cs.yale.edu/homes/aspnes/classes/223/notes.html
#include "fdf.h"

int	main(void)
{
	t_mlx	mlx;
	t_line	line;
	t_line	b;

	mlx = init("Hello world", 1920, 1080);

	line = new_line(1920/2, 100, 1920/2, -980);
	b = new_line(200, 1080/2, 1720, 1080 / 2);

	line.draw(&line, &mlx);

	mlx_loop(mlx.mlx);
}
