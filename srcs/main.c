/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 13:14:40 by nguiard           #+#    #+#             */
/*   Updated: 2021/12/29 18:48:24 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

int main(void)
{
	t_mlx	*mlx = malloc(sizeof(t_mlx));
	mlx->x = 500;
	mlx->y = 500;

	mlx->init = mlx_init();
	mlx->win = mlx_new_window(mlx->init, mlx->x, mlx->y, "FdF");
	
	t_co a;
	t_co b;

	a.x = 400;
	a.y = 300;
	a.alt = 10;

	b.x = 200;
	b.y = 200;
	b.alt = 0;
	all_line(mlx, a, b);
	mlx_string_put(mlx->init, mlx->win, 100, 50, 0xffffffff, "Bonjour");
	mlx_loop(mlx->init);
	free(mlx);
	return (0);
}
