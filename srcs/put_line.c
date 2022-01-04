/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 16:23:15 by nguiard           #+#    #+#             */
/*   Updated: 2021/12/29 18:49:15 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void all_line(t_mlx *mlx, t_co a, t_co b)
{
	t_mathline	all;

	all = init_mathline(a, b);
	printf("a.alt %d\tb.alt %d\n", a.alt, b.alt);
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
	if (a.x > mlx->x && b.x > mlx->x)
		return (0);
	if (a.y > mlx->y && b.y > mlx->y)
		return (0);
	if (a.x < 0 && b.x < 0)
		return (0);
	if (a.y < 0 && b.y < 0)
		return (0);
	if (a.x > mlx->x || a.y > mlx->y)
		return (2);
	return (1);
}

void put_line(t_mlx *mlx, t_co a, t_co b, t_mathline all)
{
	int	i;
	int	color;

	i = 0;
	a.y = a.y - a.alt;
	b.y -= b.alt;
	printf("co au debut: ax: %d\tay:%d\taalt%d\t\tbx:%d\tby:%d\tbalt%d\n", a.x, a.y, a.alt, b.x, b.y, b.alt);
	while (is_pos_ok(mlx, all, a ,b) != 0)
	{
	//	color = get_color(i, a, b);
		if (is_pos_ok(mlx, all, a ,b) == 1)
		{
			mlx_pixel_put(mlx->init, mlx->win, a.x, a.y, 0xffffffff);
	//		printf("pixel put in x = %d y = %d\n", a.x, a.y);
		}
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
			i++;
		}
	}
	printf("co a la fin: ax: %d\tay:%d\t\tbx:%d\tby:%d\n", a.x, a.y, b.x, b.y);
}
