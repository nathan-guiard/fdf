/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_touched.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:01:16 by nguiard           #+#    #+#             */
/*   Updated: 2022/01/31 12:06:53 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	quit_everything(t_all *all, int event)
{
	event += 1;
	mlx_destroy_image(all->mlx->init, all->img->img);
	mlx_destroy_window(all->mlx->init, all->mlx->win);
	mlx_destroy_display(all->mlx->init);
	free(all->mlx->init);
	free_tabtabtab(all->tab);
	exit(0);
	return (0);
}

int	zoom(int keycode, int x, int y, t_all *all)
{
	(void)x;
	(void)y;
	if (keycode == MINUS)
		all->info->zoom -= 15;
	else if (keycode == PLUS)
		all->info->zoom += 15;
	if (keycode == 5)
		all->info->zoom -= 3;
	else if (keycode == 4)
		all->info->zoom += 3;
	if (all->info->zoom < 6)
		all->info->zoom = 6;
	all_draw(all);
	return (0);
}

void	change_color(int keycode, t_all *all)
{
	if (keycode == 49)
		all->info->force_color = red;
	if (keycode == 50)
		all->info->force_color = blue;
	if (keycode == 51)
		all->info->force_color = green;
	if (keycode == 52)
		all->info->force_color = yellow;
	if (keycode == 53)
		all->info->force_color = orange;
	if (keycode == 54)
		all->info->force_color = pink;
	if (keycode == 55)
		all->info->force_color = magenta;
	if (keycode == 56)
		all->info->force_color = white;
	if (keycode == 57)
		all->info->force_color = withcode;
	if (keycode == 48)
		all->info->force_color = nocode;
	all_draw(all);
}

void	moove(int keycode, t_all *all)
{
	if (keycode == LEFT_KEY)
		all->info->base_point.x -= MOOVE_FACTOR;
	else if (keycode == RIGHT_KEY)
		all->info->base_point.x += MOOVE_FACTOR;
	if (keycode == UP_KEY)
		all->info->base_point.y -= MOOVE_FACTOR;
	if (keycode == DOWN_KEY)
		all->info->base_point.y += MOOVE_FACTOR;
	if (keycode == A_KEY)
		all->info->base_point.x -= (MOOVE_FACTOR * 5);
	if (keycode == D_KEY)
		all->info->base_point.x += (MOOVE_FACTOR * 5);
	if (keycode == W_KEY)
		all->info->base_point.y -= (MOOVE_FACTOR * 5);
	if (keycode == S_KEY)
		all->info->base_point.y += (MOOVE_FACTOR * 5);
	all_draw(all);
}

int	key_touched(int keycode, t_all *all)
{
	if (keycode == ESC)
		quit_everything(all, 0);
	if (keycode == PLUS || keycode == MINUS || keycode == 4 || keycode == 5)
		zoom(keycode, 0, 0, all);
	if (keycode >= 48 && keycode <= 57)
		change_color(keycode, all);
	if ((keycode >= LEFT_KEY && keycode <= DOWN_KEY)
		|| (keycode == A_KEY || keycode == W_KEY
			|| keycode == S_KEY || keycode == D_KEY))
		moove(keycode, all);
	if (keycode == 93 || keycode == 91 || keycode == 39 || keycode == 59)
		altitude(keycode, all);
	return (0);
}
