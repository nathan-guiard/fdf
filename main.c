/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 13:14:40 by nguiard           #+#    #+#             */
/*   Updated: 2021/12/29 13:38:10 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
int	print_key(int key, t_mlx *mlx)
{ 
	static int i;
	void *win = mlx->win;
	void *init = mlx->init;
	int y = 0;

	i++;
	while (y < 600)
		mlx_pixel_put(init, win, i, y++, 0x00ff0000 + i + y);
	if (key == ESC)
		printf("quit");
	else
		printf("%d\n", key);
	return 0;
}

void put_bg(t_mlx *mlx, int color, int x, int y)
{
	int ax;
	int ay = 0;

	while (ay < y)
	{
		ax = 0;
		while (ax < x)
			mlx_pixel_put(mlx->init, mlx->win, ax++, ay, color);
		ay++;
	}
}	

void put_cross(t_mlx *mlx, int x, int y)
{
	int curr_x = 0;
	int curr_y = 0;

	put_bg(mlx, 0x00002aff, x, y);
	while (curr_y < y)
	{
		curr_x = 0;
		while (curr_x < x)
			mlx_pixel_put(mlx->init, mlx->win, curr_x ++, curr_y, 0xff000000);
		curr_y += 50;
	}
	curr_x = 0;
	while (curr_x < x)
	{
		curr_y = 0;
		while (curr_y < y)
			mlx_pixel_put(mlx->init, mlx->win, curr_x, curr_y++, 0xff000000);
		curr_x += 50;
	}
}

void all_line(t_mlx *mlx, t_co a, t_co b)
{
	t_mathline	all;

	all = init_mathline(a, b);
	put_line(mlx, a, b, all);
}

t_mathline	init_mathline(t_co a, t_co b)
{
	t_mathline	all;

	all.dx = abs(b.x - a.x);
	all.sx = -1;
	if (a.x < b.x)
		all.sx = 1;
	all.dy = -abs(b.y - a.y);
	all.sy = -1;
	if (a.y < b.y)
		all.sy = 1;
	all.err = all.dx + all.dy;
	return (all);
}

int	is_pos_ok(t_mlx *mlx, t_mathline all, t_co a, t_co b)
{
	if (a.x == b.x && a.y == b.y)
		return (0);
	if ((a.x > mlx->x || a.x < 0) || (a.y > mlx->y || a.y < 0))
		return (0);
	return (1);
}

void put_line(t_mlx *mlx, t_co a, t_co b, t_mathline all)
{

	while (is_pos_ok(mlx, all, a ,b) == 1)
	{
		mlx_pixel_put(mlx->init, mlx->win, a.x, a.y, 0xffffffff);
		printf("pixel put in x = %d y = %d\n", a.x, a.y);
		all.e2 = 2 * all.err;
		if (all.e2 >= all.dy)
		{
			all.err += all.dy;
			a.x += all.sx;
		}
		if (all.e2 <= all.dx)
		{
			all.err += all.dx;
			a.y += all.sy;
		}
	}
}

int main(void)
{
	t_mlx	*mlx = malloc(sizeof(t_mlx));
	mlx->x = 500;
	mlx->y = 500;

	mlx->init = mlx_init();
	mlx->win = mlx_new_window(mlx->init, mlx->x, mlx->y, "FdF");
//	put_bg(mlx, 0xff007777, mlx->x, mlx->y);
	
	
	
	t_co a;
	t_co b;

	a.x = 100;
	a.y = 200;

	b.x = 200;
	b.y = 200;
	all_line(mlx, a, b);
	mlx_string_put(mlx->init, mlx->win, 100, 50, 0xffffffff, "Bonjour");
	mlx_loop(mlx->init);
	free(mlx);
	return (0);
}
