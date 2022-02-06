/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 13:45:33 by nguiard           #+#    #+#             */
/*   Updated: 2022/01/31 12:09:00 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*get_name(char *path)
{
	int		i;
	int		j;
	char	*res;

	if (ft_strchr(path, '/') == NULL)
		return (path);
	i = ft_strlen(path);
	while (path[i] != '/')
		i--;
	i++;
	res = ft_calloc(ft_strlen(path) - i + 1, sizeof(char));
	if (!res)
		return (NULL);
	j = 0;
	while (path[i + j] != '.' && path[i + j] != '\0')
	{
		res[j] = path[i + j];
		j++;
	}
	res[j] = '\0';
	return (res);
}

/*	A l'air good mais peut etre a revoir 
	les valeurs quand on pourra print plus */
int	get_zoom(char ***tab)
{
	int	x;
	int	y;
	int	res;

	res = 0;
	x = 0;
	y = 0;
	while (tab[x][y])
		y++;
	while (tab[x])
		x++;
	if (x >= y)
		res = x;
	else
		res = y;
	res = (LENGTH - 100) / res;
	res *= 3;
	res /= 4;
	if (res < 10)
		res = 10;
	return (res);
}

int	get_color_coef(char ***tab)
{
	int	i;
	int	j;
	int	res;

	i = 0;
	res = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (abs(ft_atoi(tab[i][j])) > res)
				res = abs(ft_atoi(tab[i][j]));
			j++;
		}
		i++;
	}
	if (res == 0)
		return (1);
	if (res < 15)
		return (15);
	return (res);
}

t_info	get_info(char ***parsing)
{
	t_info	info;

	info.base_point.alt = 0;
	info.base_point.x = DEFAULT_X;
	info.base_point.y = DEFAULT_Y;
	info.where = info.base_point;
	info.zoom = get_zoom(parsing);
	info.rot = rot1;
	info.color_coef = get_color_coef(parsing);
	info.force_color = nocode;
	info.alt = 5;
	return (info);
}
