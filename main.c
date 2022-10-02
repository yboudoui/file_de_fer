/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 14:51:33 by yboudoui          #+#    #+#             */
/*   Updated: 2022/10/02 15:01:53 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//http://www.cs.yale.edu/homes/aspnes/classes/223/notes.html
#include "mlx_wrapper.h"

#define WIDTH 800
#define HEIGHT 600

#include <unistd.h>
int	draw(t_window *win)
{
	static t_line line = {{0, 0}, {WIDTH, HEIGHT}};
	static t_line line2 = {{0, 0}, {WIDTH, HEIGHT}};

	use_window(*win);
	clear();
	window_put(ft_line_obj(&line));
	window_put(ft_line_obj(&line2));
	if (line.end.y != 0 && line.start.y == 0)
		line.end.y--;
	if (line.start.y != HEIGHT && line.end.y == 0)
		line.start.y++;
	if (line.end.y != HEIGHT && line.start.y == HEIGHT)
		line.end.y++;
	if (line.start.y != 0 && line.end.y == HEIGHT)
		line.start.y--;
	usleep(100);
	if (line2.end.x != 0 && line2.start.x == 0)
		line2.end.x--;
	if (line2.start.x != WIDTH && line2.end.x == 0)
		line2.start.x++;
	if (line2.end.x != WIDTH && line2.start.x == WIDTH)
		line2.end.x++;
	if (line2.start.x != 0 && line2.end.x == WIDTH)
		line2.start.x--;
	return (0);
}

int	main(int ac, char *av[])
{
	t_window	win;

	(void)ac;
	(void)av;
	if (!mlx_wrapper_init())
		return (-1);
	win = window("Hello world", WIDTH, HEIGHT);
	use_window(win);
	add_loop_hook(draw, &win);
	add_hook(2, 1L<<0, close, NULL);

	start_loop();
	free_all_mlx();
}
