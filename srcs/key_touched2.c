/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_touched2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 17:00:39 by nguiard           #+#    #+#             */
/*   Updated: 2022/01/28 18:14:59 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	altitude(int keycode, t_all *all)
{
	if (keycode == 93)
		all->info->alt += 1;
	if (keycode == 91)
		all->info->alt -= 1;
	if (keycode == 39)
		all->info->alt += 10;
	if (keycode == 59)
		all->info->alt -= 10;
	all_draw(all);
}
