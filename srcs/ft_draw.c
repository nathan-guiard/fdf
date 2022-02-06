/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 15:35:49 by nguiard           #+#    #+#             */
/*   Updated: 2022/01/28 17:01:40 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*	L'idee est de faire la ligne X puis la ligne y
	on fait une varaible where qui vas contenir
	l'endroit ou on est de base, calcule par un truc
	exterieur fait avant, qui vas avancer que une fois
	toutes les deux lignes tracees sur x, puis quand
	on a fait toute la ligne on vas a la ligne d'en
	dessous etc...										*/
void	ft_draw(char ***tab, t_img img, t_info *info)
{
	int		x;
	int		y;
	t_set	set;

	x = 0;
	y = 0;
	while (tab[x] && tab[x + 1])
	{
		info->where = define_where(*info, x, y);
		while (tab[x][y] && tab[x][y + 1])
		{
			set = define_set(tab[x][y], tab[x + 1][y], *info, DIM_X);
			all_line(img, set, info->force_color);
			set = define_set(tab[x][y], tab[x][y + 1], *info, DIM_Y);
			all_line(img, set, info->force_color);
			info->where = set.b;
			y++;
		}
		set = define_set(tab[x][y], tab[x + 1][y], *info, DIM_X);
		x++;
		all_line(img, set, info->force_color);
		y = 0;
	}
	info->where = define_where(*info, x, y);
	put_last_line(tab, img, info);
}

void	put_last_line(char ***tab, t_img img, t_info *info)
{
	int		x;
	int		y;
	t_set	set;

	x = 0;
	y = 0;
	while (tab[x + 1] != NULL)
		x++;
	while (tab[x][y] && tab[x][y + 1])
	{
		set = define_set(tab[x][y], tab[x][y + 1], *info, DIM_Y);
		all_line(img, set, info->force_color);
		info->where = set.b;
		y++;
	}
}

t_set	define_set(char *tab1, char *tab2, t_info info, int dim)
{
	t_set	set;

	set.a = info.where;
	set.a.alt = ft_atoi(tab1) * info.zoom * info.alt / (info.color_coef * 10);
	set.b.x = set.a.x + info.zoom / 2;
	if (dim == DIM_X)
		set.b.y = set.a.y + info.zoom / 3;
	else
		set.b.y = set.a.y - info.zoom / 3;
	set.b.alt = ft_atoi(tab2) * info.zoom * info.alt / (info.color_coef * 10);
	set.color = get_color(tab1, tab2, info);
	return (set);
}

t_co	define_where(t_info info, int x, int y)
{
	t_co	res;

	if (x == y && x == 0)
	{
		res = info.base_point;
		return (res);
	}
	res.alt = info.where.alt;
	res.y = info.base_point.y + ((x - y) * info.zoom / 3);
	res.x = ((x + y) * info.zoom) / 2 + info.base_point.x;
	return (res);
}

void	refresh_img(t_img img)
{
	int	x;
	int	y;
	int	*tab;

	tab = (int *)img.addr;
	x = 0;
	while (x < HEIGHT + 1)
	{
		y = 0;
		while (y < LENGTH + 1)
		{
			tab[y * HEIGHT + x] = 0x00000000;
			y++;
		}
		x++;
	}
}
