/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 16:23:15 by nguiard           #+#    #+#             */
/*   Updated: 2022/01/28 13:45:45 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	all_line(t_img img, t_set set, enum e_color force_color)
{
	t_math	all;

	set.a.y -= set.a.alt;
	set.b.y -= set.b.alt;
	if (set.a.y < 0 || set.a.x < 0 || set.b.y < 0 || set.b.x < 0)
		return ;
	all = init_mathline(set);
	put_line(img, set, all, force_color);
}

int	is_pos_ok(t_set set)
{
	if (set.a.x == set.b.x && set.a.y == set.b.y)
		return (0);
	if (set.a.x > LENGTH && set.b.x > LENGTH)
		return (0);
	if (set.a.y > HEIGHT && set.b.y > HEIGHT)
		return (0);
	if (set.a.x < 0 && set.b.x < 0)
		return (0);
	if (set.a.y < 0 && set.b.y < 0)
		return (0);
	if (set.a.x > LENGTH || set.a.y > HEIGHT)
		return (2);
	return (1);
}

void	put_line(t_img img, t_set set, t_math all, enum e_color force_color)
{
	t_co	base;

	base = base_set(set);
	while (is_pos_ok(set) != 0 && check_base(set, base) == 0)
	{
		if (is_pos_ok(set) == 1
			&& (force_color == withcode || force_color == nocode))
			my_pixel_put(&img, set.a.x, set.a.y, set.color);
		else if (is_pos_ok(set) == 1)
			my_pixel_put(&img, set.a.x, set.a.y, force_color);
		all.e2 = 2 * all.err;
		if (all.e2 >= all.dy)
		{
			all.err += all.dy;
			set.a.x += all.sx;
		}
		if (all.e2 <= all.dx)
		{
			all.err += all.dx;
			set.a.y += all.sy;
		}
	}
}

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}
