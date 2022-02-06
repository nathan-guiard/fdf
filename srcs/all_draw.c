/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 17:35:15 by nguiard           #+#    #+#             */
/*   Updated: 2022/01/29 10:21:15 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_menu(t_all *all);

void	all_draw(t_all *all)
{
	refresh_img(*all->img);
	ft_draw(all->tab, *all->img, all->info);
	put_menu(all);
	mlx_put_image_to_window(all->mlx->init, all->mlx->win, all->img->img, 0, 0);
	all_strings(all);
}

void	put_menu(t_all *all)
{
	int		x;
	t_set	set;

	x = MENU_X;
	while (++x != LENGTH + 1)
	{
		set.a.x = x;
		set.a.y = 0;
		set.a.alt = 0;
		set.b.x = x;
		set.b.y = MENU_Y;
		set.b.alt = 0;
		set.color = 0xff7a9299;
		all_line(*all->img, set, withcode);
	}
}

void	all_strings(t_all *all)
{
	mlx_string_put(all->mlx->init, all->mlx->win,
		MENU_X + 10, 20, 0xff000000, "Altitude:        [ ] ou ; '");
	mlx_string_put(all->mlx->init, all->mlx->win,
		MENU_X + 10, 35, 0xff000000, "Zoom:            - +");
	mlx_string_put(all->mlx->init, all->mlx->win,
		MENU_X + 10, 50, 0xff000000, "Deplacement:     W A S D ou Fleches");
	mlx_string_put(all->mlx->init, all->mlx->win,
		MENU_X + 10, 65, 0xff000000, "Couleurs:        1-8: Couleurs");
	mlx_string_put(all->mlx->init, all->mlx->win,
		MENU_X + 10, 80, 0xff000000,
		"                 9: Sans le code couleur");
	mlx_string_put(all->mlx->init, all->mlx->win,
		MENU_X + 10, 95, 0xff000000,
		"                 0: Avec le code couleur");
}
